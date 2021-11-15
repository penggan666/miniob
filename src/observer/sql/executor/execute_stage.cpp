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
    if(left_value->get_is_null()||right_value->get_is_null())return false;//NULL不管怎么比较都返回fasle
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
//TODO: add order 根据字段名获取对应的表名 一般用于字段表属性是NULL时, 注意如果返回多个表说明存在问题
int getTableNameByField(const char *db,const Selects &selects,char*& res_table_name,const char* field_name){
    int count=0;
    for (size_t i = 0; i < selects.relation_num; i++) {
    const char *table_name = selects.relations[i];
    Table * table = DefaultHandler::get_default().find_table(db, table_name);
    const TableMeta &table_meta = table->table_meta();
    const int field_num = table_meta.field_num();
    for (int j = 0; j < field_num; j++) {
    const FieldMeta *field_meta = table_meta.field(j);
    if (field_meta->visible()) {
      if(strcmp(field_meta->name(),field_name)){
        res_table_name=strdup(table_name);
        count++;
      }
    }
    }
  }
  return count;
}

//TODO: add order
void init_orderby(const char *db,const Selects &selects,const TupleSet& ts,std::vector<int>&order_field_indexs,std::vector<bool>& is_asc){
  
  const TupleSchema & schema=ts.get_schema();
  for(int i=selects.order_num-1;i>=0;i--){//遍历每个order
    const OrderAttr& oa=selects.orderattrs[i];
    char*  relation_name=nullptr;
    char*  attr_name=strdup(oa.attribute_name);
    if(nullptr==oa.relation_name){
      getTableNameByField(db,selects,relation_name,attr_name);//将空的表名填补上
    }else{
      relation_name=strdup(oa.relation_name);
    }
    //遍历tuple field 找对应index
    order_field_indexs.push_back(schema.index_of_field(relation_name,attr_name));
    is_asc.push_back(oa.type==OASC);
  }

}
RC tupleSetToValue(Value &result,const TupleSet& ts,const CompOp& cp){
    RC rc = RC::SUCCESS;
    if(ts.get_schema().fields().size()!=1){//排除错误情况: a>(1,2,3) 多列值的情况
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
    }
    if(cp!=IN&&cp!=NOT_IN){//非in和not in就直接返回一个值, 第一行第一列
    const TupleField tf=ts.get_schema().field(0);
    result.type=tf.type();
    if(ts.is_empty()){//处理子查询结果为空的情况
        result.data= nullptr;
        return rc;
    }
    if(ts.size()!=1){//排除错误情况: a>多行
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
    }
        LOG_ERROR("ts.size(): %d",ts.size());
    const std::shared_ptr<TupleValue> tv=ts.get(0).values()[0];
    tv->get_real_value(result);
    //TODO: 注意日期应该转为string，回来需要补上
  }else{//返回数组
    const TupleField tf=ts.get_schema().field(0);
    size_t tuple_size=ts.size();
    switch (tf.type())
    {
    case CHARS:
      result.type=ARR_CHARS;
        if(ts.is_empty()){//处理子查询结果为空的情况
            result.data= nullptr;
            return rc;
        }
      result.data=malloc(sizeof(char*)*tuple_size+sizeof(size_t));//void->char**
      memcpy(result.data,&tuple_size,sizeof (tuple_size));//最前面保存数组大小
      break;
    case INTS:
      result.type=ARR_INTS;
        if(ts.is_empty()){//处理子查询结果为空的情况
            result.data= nullptr;
            return rc;
        }
      result.data=malloc(sizeof(int)*tuple_size+sizeof(size_t));
      memcpy(result.data,&tuple_size,sizeof (tuple_size));
      break;
    case FLOATS:
      result.type=ARR_FLOATS;
        if(ts.is_empty()){//处理子查询结果为空的情况
            result.data= nullptr;
            return rc;
        }
      result.data=malloc(sizeof(float)*tuple_size+sizeof(size_t));
      memcpy(result.data,&tuple_size,sizeof (tuple_size));
      break;
    default:
      result.type=UNDEFINED;
      break;
    }
    //遍历每一条记录, 追加到result里
    for(size_t i=0;i<tuple_size;i++){
      ts.tuples()[i].values()[0]->append_real_value(result,i);//只考虑第一列
    }
  }
    return rc;
}
//根据select获取查询结果， 保存到result里
RC selectToTupleSet(const char *db, SessionEvent *session_event, Selects &selects,TupleSet& result,int& is_mul_table){
    RC rc = RC::SUCCESS;
  Session *session = session_event->get_client()->session;
  Trx *trx = session->current_trx();
  if(selects.sub_num>0){//如果存在子查询
    for(size_t i=0;i<selects.condition_num;i++){//遍历所有condition, 将其中的子查询修改为可以正常使用的值
      Condition &condition = selects.conditions[i];
      if(condition.left_is_attr&&condition.left_attr.sub_select_idx>-1){//左边属性是子查询
        //根据比较符号非in或notin 可以知道应该为单个值
        TupleSet sub_select_left;
        int tmp;//注意子查询用不到, 只有第一层需要判断是否是多表查询, 来进行输出
        rc=selectToTupleSet(db, session_event, selects.sub_select[condition.left_attr.sub_select_idx],sub_select_left,tmp);//获取子查询结果
        if (rc != RC::SUCCESS) {
          LOG_ERROR("sub select fail!!!\n");
          session_event->set_response("FAILURE\n");
          end_trx_if_need(session, trx, false);
          return rc;
        }
        condition.left_is_attr=0;//改为value
        rc=tupleSetToValue(condition.left_value,sub_select_left,condition.comp);//将子查询改为可以正常使用的值
          if (rc != RC::SUCCESS) {
              LOG_ERROR("tupleSetToValue fail!!!\n");
              return rc;
          }
      }
      
      if(condition.right_is_attr&&condition.right_attr.sub_select_idx>-1){//右边属性是子查询
        TupleSet sub_select_right;
        int tmp;
        rc=selectToTupleSet(db, session_event, selects.sub_select[condition.right_attr.sub_select_idx],sub_select_right,tmp);//获取子查询结果
        if (rc != RC::SUCCESS) {
          LOG_ERROR("sub select fail!!!\n");
          session_event->set_response("FAILURE\n");
          end_trx_if_need(session, trx, false);
          return rc;
        }
        condition.right_is_attr=0;//改为value
        rc=tupleSetToValue(condition.right_value,sub_select_right,condition.comp);//将子查询改为可以正常使用的值
          if (rc != RC::SUCCESS) {
              LOG_ERROR("tupleSetToValue fail!!!\n");
              return rc;
          }
      }
    }
  }    
  // 把所有的表和只跟这张表关联的condition都拿出来，生成最底层的select 执行节点
  std::vector<SelectExeNode *> select_nodes;
  for (size_t i = 0; i < selects.relation_num; i++) {
    const char *table_name = selects.relations[i];
    SelectExeNode *select_node = new SelectExeNode;
    rc = create_selection_executor(trx, selects, db, table_name, *select_node);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("create_selection_executor fail!!!\n");
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
  LOG_ERROR("create_selection_executor success!!!\n");
  std::vector<TupleSet> tuple_sets;
  for (SelectExeNode *&node: select_nodes) {
    TupleSet tuple_set;
    rc = node->execute(tuple_set);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("execute fail");
      for (SelectExeNode *& tmp_node: select_nodes) {
        delete tmp_node;
      }
      end_trx_if_need(session, trx, false);
      return rc;
    } else {
      // tuple_sets.push_back(std::move(tuple_set));
      //修改顺序
      // LOG_ERROR("tuple_set: %d",tuple_set.size());
      tuple_sets.insert(tuple_sets.begin(),std::move(tuple_set));
    }
  }
  LOG_ERROR("execute success!!!\n");
  //对多个单表查询的结果进行处理, 并赋值给result
  if (tuple_sets.size() > 1) {
    is_mul_table=1;
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
    result=std::move(join_left_set);
  } else {
    // 当前只查询一张表，直接返回结果即可
    //TODO: 这里添加对聚合函数的处理,目前只做一张表的
    Tuple tuple;
    TupleSchema tupleSchema;
    std::vector<TupleField> tuple_fileds=tuple_sets.front().get_schema().fields();
    int count_star_flag=1;
    for(int i=0;i<tuple_fileds.size();i++){
        switch (tuple_fileds[i].aggregate_name()) {
            case AGG_MIN:{
                std::string const &min_field_name =
                        std::string("MIN(") + std::string(tuple_fileds[i].field_name()) + std::string(")");
                tupleSchema.add(tuple_fileds[i].type(), tuple_fileds[i].table_name(), min_field_name.c_str(), AGG_MIN);
                if (tuple_sets.front().size()>0)
                    tuple.add(tuple_sets.front().minTuple(i)[i]);
            }
                break;
            case AGG_MAX: {
                std::string const &max_field_name =
                        std::string("MAX(") + std::string(tuple_fileds[i].field_name()) + std::string(")");
                tupleSchema.add(tuple_fileds[i].type(), tuple_fileds[i].table_name(), max_field_name.c_str(), AGG_MAX);
                if (tuple_sets.front().size()>0)
                    tuple.add(tuple_sets.front().maxTuple(i)[i]);
            }
                break;
            case AGG_COUNT:{
                std::string const &count_field_name =
                        std::string("COUNT(") + std::string(tuple_fileds[i].field_name()) + std::string(")");
                tupleSchema.add(INTS, tuple_fileds[i].table_name(), count_field_name.c_str(), AGG_COUNT);
                tuple.add(tuple_sets.front().countTupleColumn(i),0);
            }
                break;
            case AGG_COUNT_STAR:{
                if (count_star_flag) {
                    tupleSchema.add(INTS, tuple_fileds[i].table_name(), "COUNT(*)", AGG_COUNT);
                    tuple.add(tuple_sets.front().countTupleStar(),0);
                    count_star_flag=0;
                }
            }
                break;
            case AGG_AVG:{
                std::string const &avg_field_name =
                        std::string("AVG(") + std::string(tuple_fileds[i].field_name()) + std::string(")");
                tupleSchema.add(FLOATS, tuple_fileds[i].table_name(), avg_field_name.c_str(), AGG_AVG);
                if (tuple_sets.front().size()>0){
                    float result = tuple_sets.front().avgTuple(i);
                    if (result==-1)
                        tuple.add(result,1);
                    else
                        tuple.add(result,0);
                }
            }
            case AGG_NO:
                break;
        }
    }
    if (tupleSchema.fields().size()!=0){
        TupleSet tupleSet;
        if (tuple.size()>0)
            tupleSet.add(std::move(tuple));
        tupleSet.set_schema(tupleSchema);
        result=std::move(tupleSet);//处理结果存到返回值
    }else {
        result=std::move(tuple_sets.front());//处理结果存到返回值
    }
  }

  for (SelectExeNode *& tmp_node: select_nodes) {
    delete tmp_node;
  }
  return rc;
}
// 这里没有对输入的某些信息做合法性校验，比如查询的列名、where条件中的列名等，没有做必要的合法性校验
// 需要补充上这一部分. 校验部分也可以放在resolve，不过跟execution放一起也没有关系
RC ExecuteStage::do_select(const char *db, Query *sql, SessionEvent *session_event) {
  LOG_ERROR("start do_select!!!\n");
  RC rc = RC::SUCCESS;
  Session *session = session_event->get_client()->session;
  Trx *trx = session->current_trx();
  Selects &selects = sql->sstr.selection;
  TupleSet result;
  int is_mul_table=0;
  rc=selectToTupleSet(db,session_event,selects,result,is_mul_table);
  if (rc != RC::SUCCESS) {
      LOG_ERROR("sub select fail!!!\n");
      session_event->set_response("FAILURE\n");
      end_trx_if_need(session, trx, false);
      return rc;
  }
  //TODO: 处理返回的RC异常
  std::stringstream ss;
  //order 排序 用于输出
  if(selects.order_num>0){
      //TODO: add order 根据select里order属性 获取对应属性在结果Tuple的index和排序方式(ASC或DESC)
      std::vector<int> order_field_indexs;
      std::vector<bool> is_asc;
      init_orderby(db,selects,result,order_field_indexs,is_asc);
      result.sortTupleByOrder(order_field_indexs,is_asc);
  }
  
  //打印输出
  if(is_mul_table==1){//多表, 需要处理一下打印打列顺序
    std::vector<int> realField;
    getPrintIndex(selects,result.get_schema().fields(),realField);
    result.print_rm_tmp(ss,realField);
  }else{
    result.print(ss);
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

static RC schema_add_field(Table *table, const char *field_name, TupleSchema &schema, int aggregate_name=0) {
  const FieldMeta *field_meta = table->table_meta().field(field_name);
  if (nullptr == field_meta) {
    LOG_WARN("No such field. %s.%s", table->name(), field_name);
    return RC::SCHEMA_FIELD_MISSING;
  }
  //TODO: 如果AVG的类型是CHARS或者DATES就报错
  if ((field_meta->type()==CHARS || field_meta->type()==DATES) && aggregate_name==AGG_AVG){
    LOG_WARN("CHARS OR DATES TYPE DON'T SUPPORT AVG");
    return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  }

  schema.add_if_not_exists(field_meta->type(), table->name(), field_meta->name(), aggregate_name);
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
//用于比较一开始就是两个值的condition, 如果是true, 该条件可以直接跳过过
bool cmp_value(const Value& left_value_,const Value& right_value_,const CompOp& comp){
  char *left_value = (char *)left_value_.data;
  char *right_value = (char *)right_value_.data;
  if(left_value== nullptr || right_value == nullptr)
      return false;
  int cmp_result = 0;
  switch (left_value_.type) {
    case CHARS: {  // 字符串都是定长的，直接比较
      // 按照C字符串风格来定
      cmp_result = strcmp(left_value, right_value);
    } break;
    //TODO: add date
    case DATES:
    case INTS: {
      // 没有考虑大小端问题
      // 对int和float，要考虑字节对齐问题,有些平台下直接转换可能会跪
      int left = *(int *)left_value;
      int right = *(int *)right_value;
      cmp_result = left - right;
    } break;
    case FLOATS: {
      float left = *(float *)left_value;
      float right = *(float *)right_value;
      cmp_result = (int)(left - right);
    } break;
    default: {
    }
  }

  switch (comp) {
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

  LOG_PANIC("Never should print this.");
  return cmp_result;  // should not go here
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
        TupleSchema::from_table(table, schema, attr.aggregate_name);
        if (attr.aggregate_name == AGG_NO)
            break; // 没有校验，给出* 之后，再写字段的错误
      } else {
        // 列出这张表相关字段
        RC rc = schema_add_field(table, attr.attribute_name, schema, attr.aggregate_name);
        if (rc != RC::SUCCESS) {
          LOG_ERROR("schema_add_field fail!!!\n");
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
        LOG_ERROR("condition_filter init fail!!!\n");
        return rc;
      }
      //1=1这种情况直接无视
      if(condition.left_is_attr == 0 && condition.right_is_attr==0&&cmp_value(condition.left_value,condition.right_value,condition.comp)){
        LOG_ERROR("jump !!!\n");
        continue;
      }
      
      condition_filters.push_back(condition_filter);
    }//TODO: add join 需要将跨表的属性列加到最终获取的列上
    else if(condition.left_is_attr == 1 && condition.right_is_attr == 1 &&
            match_table(selects, condition.left_attr.relation_name, table_name))//左右都是属性值,但只有左属性值属于当前表
            {
              Table * table_right = DefaultHandler::get_default().find_table(db, condition.right_attr.relation_name);
              ////如果左右属性类型不同返回fasle
              if(!isRightCmp(*table,*table_right,condition)){
                LOG_ERROR("left isRightCmp fail!!!\n");
                return RC::SCHEMA_FIELD_TYPE_MISMATCH;
              }
              schema_add_field(table,condition.left_attr.attribute_name,schema);
    }else if(condition.left_is_attr == 1 && condition.right_is_attr == 1 &&
    match_table(selects, condition.right_attr.relation_name, table_name)){//左右都是属性值,但只有右属性值属于当前表
        Table * table_left = DefaultHandler::get_default().find_table(db, condition.left_attr.relation_name);
        if(!isRightCmp(*table_left,*table,condition)){
          LOG_ERROR("right isRightCmp fail!!! %s-%s-%d\n",condition.right_attr.attribute_name,condition.left_attr.attribute_name,condition.comp);
          return RC::SCHEMA_FIELD_TYPE_MISMATCH;
        }
        schema_add_field(table,condition.right_attr.attribute_name,schema);
    }
  }
  return select_node.init(trx, table, std::move(schema), std::move(condition_filters));
}
