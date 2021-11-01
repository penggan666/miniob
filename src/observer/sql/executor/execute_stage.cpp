/* Copyright (c) 2021 Xie Meiyi(xiemeiyi@hust.edu.cn) and OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Longda on 2021/4/13.
//

#include <string>
#include <sstream>

#include "execute_stage.h"

#include "common/io/io.h"
#include "common/log/log.h"
#include "common/seda/timer_stage.h"
#include "common/lang/string.h"
#include "session/session.h"
#include "event/storage_event.h"
#include "event/sql_event.h"
#include "event/session_event.h"
#include "event/execution_plan_event.h"
#include "sql/executor/execution_node.h"
#include "sql/executor/tuple.h"
#include "storage/common/table.h"
#include "storage/default/default_handler.h"
#include "storage/common/condition_filter.h"
#include "storage/trx/trx.h"

using namespace common;

RC create_selection_executor(Trx *trx, const Selects &selects, const char *db, const char *table_name, SelectExeNode &select_node);

//! Constructor
ExecuteStage::ExecuteStage(const char *tag) : Stage(tag) {}

//! Destructor
ExecuteStage::~ExecuteStage() {}

//! Parse properties, instantiate a stage object
Stage *ExecuteStage::make_stage(const std::string &tag) {
  ExecuteStage *stage = new (std::nothrow) ExecuteStage(tag.c_str());
  if (stage == nullptr) {
    LOG_ERROR("new ExecuteStage failed");
    return nullptr;
  }
  stage->set_properties();
  return stage;
}

//! Set properties for this object set in stage specific properties
bool ExecuteStage::set_properties() {
  //  std::string stageNameStr(stageName);
  //  std::map<std::string, std::string> section = theGlobalProperties()->get(
  //    stageNameStr);
  //
  //  std::map<std::string, std::string>::iterator it;
  //
  //  std::string key;

  return true;
}

//! Initialize stage params and validate outputs
bool ExecuteStage::initialize() {
  LOG_TRACE("Enter");

  std::list<Stage *>::iterator stgp = next_stage_list_.begin();
  default_storage_stage_ = *(stgp++);
  mem_storage_stage_ = *(stgp++);

  LOG_TRACE("Exit");
  return true;
}

//! Cleanup after disconnection
void ExecuteStage::cleanup() {
  LOG_TRACE("Enter");

  LOG_TRACE("Exit");
}

void ExecuteStage::handle_event(StageEvent *event) {
  LOG_TRACE("Enter\n");

  handle_request(event);

  LOG_TRACE("Exit\n");
  return;
}

void ExecuteStage::callback_event(StageEvent *event, CallbackContext *context) {
  LOG_TRACE("Enter\n");

  // here finish read all data from disk or network, but do nothing here.
  ExecutionPlanEvent *exe_event = static_cast<ExecutionPlanEvent *>(event);
  SQLStageEvent *sql_event = exe_event->sql_event();
  sql_event->done_immediate();

  LOG_TRACE("Exit\n");
  return;
}

void ExecuteStage::handle_request(common::StageEvent *event) {
  ExecutionPlanEvent *exe_event = static_cast<ExecutionPlanEvent *>(event);
  SessionEvent *session_event = exe_event->sql_event()->session_event();
  Query *sql = exe_event->sqls();
  const char *current_db = session_event->get_client()->session->get_current_db().c_str();

  CompletionCallback *cb = new (std::nothrow) CompletionCallback(this, nullptr);
  if (cb == nullptr) {
    LOG_ERROR("Failed to new callback for ExecutionPlanEvent");
    exe_event->done_immediate();
    return;
  }
  exe_event->push_callback(cb);

  switch (sql->flag) {
    case SCF_SELECT: { // select
      do_select(current_db, sql, exe_event->sql_event()->session_event());
      exe_event->done_immediate();
    }
    break;

    case SCF_INSERT:
    case SCF_UPDATE:
    case SCF_DELETE:
    case SCF_CREATE_TABLE:
    case SCF_SHOW_TABLES:
    case SCF_DESC_TABLE:
    case SCF_DROP_TABLE:
    case SCF_CREATE_INDEX:
    case SCF_DROP_INDEX: 
    case SCF_LOAD_DATA: {
      StorageEvent *storage_event = new (std::nothrow) StorageEvent(exe_event);
      if (storage_event == nullptr) {
        LOG_ERROR("Failed to new StorageEvent");
        event->done_immediate();
        return;
      }

      default_storage_stage_->handle_event(storage_event);
    }
    break;
    case SCF_SYNC: {
      RC rc = DefaultHandler::get_default().sync();
      session_event->set_response(strrc(rc));
      exe_event->done_immediate();
    }
    break;
    case SCF_BEGIN: {
      session_event->get_client()->session->set_trx_multi_operation_mode(true);
      session_event->set_response(strrc(RC::SUCCESS));
      exe_event->done_immediate();
    }
    break;
    case SCF_COMMIT: {
      Trx *trx = session_event->get_client()->session->current_trx();
      RC rc = trx->commit();
      session_event->get_client()->session->set_trx_multi_operation_mode(false);
      session_event->set_response(strrc(rc));
      exe_event->done_immediate();
    }
    break;
    case SCF_ROLLBACK: {
      Trx *trx = session_event->get_client()->session->current_trx();
      RC rc = trx->rollback();
      session_event->get_client()->session->set_trx_multi_operation_mode(false);
      session_event->set_response(strrc(rc));
      exe_event->done_immediate();
    }
    break;
    case SCF_HELP: {
      const char *response = "show tables;\n"
          "desc `table name`;\n"
          "create table `table name` (`column name` `column type`, ...);\n"
          "create index `index name` on `table` (`column`);\n"
          "insert into `table` values(`value1`,`value2`);\n"
          "update `table` set column=value [where `column`=`value`];\n"
          "delete from `table` [where `column`=`value`];\n"
          "select [ * | `columns` ] from `table`;\n";
      session_event->set_response(response);
      exe_event->done_immediate();
    }
    break;
    case SCF_EXIT: {
      // do nothing
      const char *response = "Unsupported\n";
      session_event->set_response(response);
      exe_event->done_immediate();
    }
    break;
    default: {
      exe_event->done_immediate();
      LOG_ERROR("Unsupported command=%d\n", sql->flag);
    }
  }
}

void end_trx_if_need(Session *session, Trx *trx, bool all_right) {
  if (!session->is_trx_multi_operation_mode()) {
    if (all_right) {
      trx->commit();
    } else {
      trx->rollback();
    }
  }
}
CompOp rever_com(const CompOp& c){//反转比较符号
  switch (c)
  {
  case LESS_EQUAL:
    return GREAT_EQUAL;
  case GREAT_EQUAL:
    return LESS_EQUAL;
  case LESS_THAN:
  return GREAT_THAN;
  case GREAT_THAN:
  return LESS_THAN;
  default:
    return c;
  }
}
//判断TupleSet是是否有对应attr如果有返回index, 没有返回-1
int getIndexOfCondition(const TupleSet& tuple_set,const RelAttr& attr){
  TupleSchema ts=tuple_set.get_schema();
  std::vector<TupleField> fileds=ts.fields();
  for(int i=0;i<fileds.size();i++){
    if(strcmp(fileds[i].table_name(),attr.relation_name)==0&&strcmp(fileds[i].field_name(),attr.attribute_name)==0){
      return i;
    }
  }
  return -1;
}
void init_join(const TupleSet& join_left_set,const TupleSet& join_right_set,const Condition* conditions,int condition_num,std::vector<std::vector<int>> &inv_field,std::vector<CompOp> &inv_com){
  for(int i=0;i<condition_num;i++){
    Condition c=conditions[i];
    if(c.left_is_attr&&c.right_is_attr&&strcmp(c.left_attr.relation_name,c.right_attr.relation_name)!=0){//左右都是属性列, 并且所属表不同
      int left_index,right_index;
      if((left_index=getIndexOfCondition(join_left_set,c.left_attr))!=-1&&((right_index=getIndexOfCondition(join_right_set,c.right_attr))!=-1)){//判断左边在左Tuple,比较理想的状况
        inv_field.push_back({left_index,right_index,});
        inv_com.push_back(c.comp);
      }else if((left_index=getIndexOfCondition(join_left_set,c.right_attr))!=-1&&((right_index=getIndexOfCondition(join_right_set,c.left_attr))!=-1)){
        inv_field.push_back({left_index,right_index});
        inv_com.push_back(rever_com(c.comp));//需要反转一下比较符 比如大于改为小于
      }
    }
  }
}
bool isRightRecord(std::shared_ptr<TupleValue> left_value,std::shared_ptr<TupleValue> right_value,CompOp& comp_op_){
    int cmp_result = left_value->compare(*right_value);
    switch (comp_op_) {
    case EQUAL_TO:
      return 0 == cmp_result;
    case LESS_EQUAL:
      return cmp_result <= 0;
    case NOT_EQUAL:
      return cmp_result != 0;
    case LESS_THAN:
      return cmp_result < 0;
    case GREAT_EQUAL:
      return cmp_result >= 0;
    case GREAT_THAN:
      return cmp_result > 0;
    default:
      break;
  }
  return false;
}
//TODO: add join join tuple
TupleSet tuple_join(TupleSet& join_left_set,const TupleSet& join_right_set,const Condition* conditions,int condition_num){
  TupleSet result;
  std::vector<std::vector<int>> inv_field;//左右涉及的列, 例如(2,1)表示对join_left_set index2列和join_right_set index1列比较
  std::vector<CompOp> inv_com;//比较符号
  init_join(join_left_set,join_right_set,conditions,condition_num,inv_field,inv_com);//负责获取涉及两个表的过滤
  for(const Tuple& item_left:join_left_set.tuples()){
    for(const Tuple& item_right:join_right_set.tuples()){
      //对笛卡儿积的每条记录, 判断是否符合所有条件
      bool is_right_record=true;
      for(int i=0;i<inv_field.size();i++){
        if(!isRightRecord(item_left.values()[inv_field[i][0]],item_right.values()[inv_field[i][1]],inv_com[i])){
          is_right_record=false;
          break;
        }
      }
      
      if(is_right_record){//该组合符合所有条件
        Tuple t;
        for(std::shared_ptr<TupleValue> tv:item_left.values()){
          t.add(tv);
        }
        for(std::shared_ptr<TupleValue> tv2:item_right.values()){
          t.add(tv2);    
        }
        
        result.add(std::move(t));
      }
    }
  }
  TupleSchema res_schema;
  res_schema.append(join_left_set.get_schema());
  res_schema.append(join_right_set.get_schema());
  result.set_schema(res_schema);
  return result;
}
//TODO: add join 最后展示要按照select时的顺序
void getPrintIndex(const Selects &selects,const std::vector<TupleField> &fields,std::vector<int>& realField){
  for(int i=selects.attr_num-1;i>=0;i--){
    const RelAttr &attr=selects.attributes[i];
    if(nullptr==attr.relation_name&&(0==strcmp("*",attr.attribute_name))){//单独一个*, 所有字段都加入
      for(int j=0;j<fields.size();j++){
        realField.push_back(j);//直接返回顺序打印就行
      }
    }else if(0==strcmp("*",attr.attribute_name)){//带* 但有表名, 将所有该表的加入
      for(int j=0;j<fields.size();j++){
        if(strcmp(fields[j].table_name(),attr.relation_name)==0){
          realField.push_back(j);
        }
      }
    }else{//既有表明, 又有属性名
      for(int j=0;j<fields.size();j++){
        if(strcmp(fields[j].table_name(),attr.relation_name)==0&&strcmp(fields[j].field_name(),attr.attribute_name)==0){
          realField.push_back(j);
        }
      }
    }
  }
}
// 这里没有对输入的某些信息做合法性校验，比如查询的列名、where条件中的列名等，没有做必要的合法性校验
// 需要补充上这一部分. 校验部分也可以放在resolve，不过跟execution放一起也没有关系
RC ExecuteStage::do_select(const char *db, Query *sql, SessionEvent *session_event) {

  RC rc = RC::SUCCESS;
  Session *session = session_event->get_client()->session;
  Trx *trx = session->current_trx();
  const Selects &selects = sql->sstr.selection;
  // 把所有的表和只跟这张表关联的condition都拿出来，生成最底层的select 执行节点
  std::vector<SelectExeNode *> select_nodes;
  for (size_t i = 0; i < selects.relation_num; i++) {
    const char *table_name = selects.relations[i];
    SelectExeNode *select_node = new SelectExeNode;
    rc = create_selection_executor(trx, selects, db, table_name, *select_node);
    
    if (rc != RC::SUCCESS) {
      session_event->set_response("FAILURE\n");
      delete select_node;
      for (SelectExeNode *& tmp_node: select_nodes) {
        delete tmp_node;
      }
      end_trx_if_need(session, trx, false);
      return rc;
    }
    select_nodes.push_back(select_node);
  }

  if (select_nodes.empty()) {
    LOG_ERROR("No table given");
    end_trx_if_need(session, trx, false);
    return RC::SQL_SYNTAX;
  }
  // LOG_ERROR("create_selection_executor success!!!\n");
  std::vector<TupleSet> tuple_sets;
  for (SelectExeNode *&node: select_nodes) {
    TupleSet tuple_set;
    rc = node->execute(tuple_set);
    if (rc != RC::SUCCESS) {
      for (SelectExeNode *& tmp_node: select_nodes) {
        delete tmp_node;
      }
      end_trx_if_need(session, trx, false);
      return rc;
    } else {
      // tuple_sets.push_back(std::move(tuple_set));
      //修改顺序
      tuple_sets.insert(tuple_sets.begin(),std::move(tuple_set));
    }
  }

  std::stringstream ss;
  if (tuple_sets.size() > 1) {
    //TODO: add join 对tuple进行join操作
    // //初始化schema
    TupleSet join_left_set;
    int skip=true;
    for(const auto &join_right_set: tuple_sets){//遍历所有表的查询结果
      if(skip){//第一次初始化
        skip=false;
        join_left_set.set_schema(join_right_set.get_schema());
        for(const Tuple& item_right:join_right_set.tuples()){
          Tuple tmp;
          for(std::shared_ptr<TupleValue> t:item_right.values()){
            tmp.add(t);
          }
          join_left_set.add(std::move(tmp));
        }
        continue;
      }
      join_left_set=tuple_join(join_left_set,join_right_set,selects.conditions,selects.condition_num);
    }
    std::vector<int> realField;
    getPrintIndex(selects,join_left_set.get_schema().fields(),realField);
    join_left_set.print_rm_tmp(ss,realField);
  } else {
    // 当前只查询一张表，直接返回结果即可
    tuple_sets.front().print(ss);
  }

  for (SelectExeNode *& tmp_node: select_nodes) {
    delete tmp_node;
  }
  session_event->set_response(ss.str());
  end_trx_if_need(session, trx, true);
  return rc;
}

bool match_table(const Selects &selects, const char *table_name_in_condition, const char *table_name_to_match) {
  if (table_name_in_condition != nullptr) {
    return 0 == strcmp(table_name_in_condition, table_name_to_match);
  }

  return selects.relation_num == 1;
}

static RC schema_add_field(Table *table, const char *field_name, TupleSchema &schema) {
  const FieldMeta *field_meta = table->table_meta().field(field_name);
  if (nullptr == field_meta) {
    LOG_WARN("No such field. %s.%s", table->name(), field_name);
    return RC::SCHEMA_FIELD_MISSING;
  }

  schema.add_if_not_exists(field_meta->type(), table->name(), field_meta->name());
  return RC::SUCCESS;
}
  //TODO:add join 判断两个表中对比属性是否类型相同
  bool isRightCmp(Table& left_table,Table&right_table,const Condition& condition){
    AttrType type_left = UNDEFINED;
    AttrType type_right = UNDEFINED;
    const TableMeta &table_meta = left_table.table_meta();
    const FieldMeta *field_left = table_meta.field(condition.left_attr.attribute_name);
    type_left = field_left->type();

    const TableMeta &table_meta2 = right_table.table_meta();
    const FieldMeta *field_left2 = table_meta2.field(condition.right_attr.attribute_name);
    type_right = field_left2->type();
    if (type_left != type_right) return false;
    return true;
  }
// 把所有的表和只跟这张表关联的condition都拿出来，生成最底层的select 执行节点
RC create_selection_executor(Trx *trx, const Selects &selects, const char *db, const char *table_name, SelectExeNode &select_node) {
  // 列出跟这张表关联的Attr
  TupleSchema schema;
  Table * table = DefaultHandler::get_default().find_table(db, table_name);
  if (nullptr == table) {
    LOG_WARN("No such table [%s] in db [%s]", table_name, db);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }
  
  for (int i = selects.attr_num - 1; i >= 0; i--) {
    const RelAttr &attr = selects.attributes[i];
    if (nullptr == attr.relation_name || 0 == strcmp(table_name, attr.relation_name)) {
      if (0 == strcmp("*", attr.attribute_name)) {
        // 列出这张表所有字段
        TupleSchema::from_table(table, schema);
        break; // 没有校验，给出* 之后，再写字段的错误
      } else {
        // 列出这张表相关字段
        RC rc = schema_add_field(table, attr.attribute_name, schema);
        if (rc != RC::SUCCESS) {
          return rc;
        }
      }
    }
  }
  
  // 找出仅与此表相关的过滤条件, 或者都是值的过滤条件
  std::vector<DefaultConditionFilter *> condition_filters;
  for (size_t i = 0; i < selects.condition_num; i++) {
    const Condition &condition = selects.conditions[i];
    if ((condition.left_is_attr == 0 && condition.right_is_attr == 0) || // 两边都是值
        (condition.left_is_attr == 1 && condition.right_is_attr == 0 && match_table(selects, condition.left_attr.relation_name, table_name)) ||  // 左边是属性右边是值
        (condition.left_is_attr == 0 && condition.right_is_attr == 1 && match_table(selects, condition.right_attr.relation_name, table_name)) ||  // 左边是值，右边是属性名
        (condition.left_is_attr == 1 && condition.right_is_attr == 1 &&
            match_table(selects, condition.left_attr.relation_name, table_name) && match_table(selects, condition.right_attr.relation_name, table_name)) // 左右都是属性名，并且表名都符合
        ) {
      DefaultConditionFilter *condition_filter = new DefaultConditionFilter();
      RC rc = condition_filter->init(*table, condition);
      if (rc != RC::SUCCESS) {
        delete condition_filter;
        for (DefaultConditionFilter * &filter : condition_filters) {
          delete filter;
        }
        return rc;
      }
      condition_filters.push_back(condition_filter);
    }//TODO: add join 需要将跨表的属性列加到最终获取的列上
    else if(condition.left_is_attr == 1 && condition.right_is_attr == 1 &&
            match_table(selects, condition.left_attr.relation_name, table_name))//左右都是属性值,但只有左属性值属于当前表
            {
              Table * table_right = DefaultHandler::get_default().find_table(db, condition.right_attr.relation_name);
              ////如果左右属性类型不同返回fasle
              if(!isRightCmp(*table,*table_right,condition)){
                return RC::SCHEMA_FIELD_TYPE_MISMATCH;
              }
              schema_add_field(table,condition.left_attr.attribute_name,schema);
    }else if(match_table(selects, condition.right_attr.relation_name, table_name)){//左右都是属性值,但只有右属性值属于当前表
        Table * table_left = DefaultHandler::get_default().find_table(db, condition.left_attr.relation_name);
        if(!isRightCmp(*table_left,*table,condition)){
          return RC::SCHEMA_FIELD_TYPE_MISMATCH;
        }
        schema_add_field(table,condition.right_attr.attribute_name,schema);
    }
  }
  
  return select_node.init(trx, table, std::move(schema), std::move(condition_filters));
}
