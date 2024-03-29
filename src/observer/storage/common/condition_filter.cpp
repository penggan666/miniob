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
// Created by Wangyunlai on 2021/5/7.
//

#include <stddef.h>
#include "tools/simple_tool.h"
#include "condition_filter.h"
#include "record_manager.h"
#include "common/log/log.h"
#include "storage/common/table.h"

using namespace common;

ConditionFilter::~ConditionFilter()
{}

DefaultConditionFilter::DefaultConditionFilter()
{
  left_.is_attr = false;
  left_.attr_length = 0;
  left_.attr_offset = 0;
  left_.value = nullptr;

  right_.is_attr = false;
  right_.attr_length = 0;
  right_.attr_offset = 0;
  right_.value = nullptr;
}
DefaultConditionFilter::~DefaultConditionFilter()
{}

RC DefaultConditionFilter::init(const ConDesc &left, const ConDesc &right, AttrType attr_type, CompOp comp_op)
{
  //TODO: add date
  if (attr_type < UNDEFINED || attr_type > ARR_FLOATS) {
    LOG_ERROR("Invalid condition with unsupported attribute type: %d", attr_type);
    return RC::INVALID_ARGUMENT;
  }

  if (comp_op < EQUAL_TO || comp_op >= NO_OP) {
    LOG_ERROR("Invalid condition with unsupported compare operation: %d", comp_op);
    return RC::INVALID_ARGUMENT;
  }

  left_ = left;
  right_ = right;
  attr_type_ = attr_type;
  comp_op_ = comp_op;
  return RC::SUCCESS;
}

RC DefaultConditionFilter::init(Table &table, const Condition &condition)
{
  const TableMeta &table_meta = table.table_meta();
  ConDesc left;
  ConDesc right;

  AttrType type_left = UNDEFINED;
  AttrType type_right = UNDEFINED;

  if (1 == condition.left_is_attr) {
    left.is_attr = true;
    const FieldMeta *field_left = table_meta.field(condition.left_attr.attribute_name);
    if (nullptr == field_left) {
      LOG_WARN("No such field in condition. %s.%s", table.name(), condition.left_attr.attribute_name);
      return RC::SCHEMA_FIELD_MISSING;
    }
    left.attr_length = field_left->len();
    left.attr_offset = field_left->offset();
    //TODO:add text 为了能找到对应data文件
    left.base_dir= strdup(table.base());
    left.table_name= strdup(table.name());
    left.attr_name= strdup(field_left->name());

    left.value = nullptr;

    type_left = field_left->type();
  } else {
    left.is_attr = false;
    left.value = condition.left_value.data;  // 校验type 或者转换类型
    type_left = condition.left_value.type;

    left.attr_length = 0;
    left.attr_offset = 0;
  }

  if (1 == condition.right_is_attr) {
    right.is_attr = true;
    const FieldMeta *field_right = table_meta.field(condition.right_attr.attribute_name);
    if (nullptr == field_right) {
      LOG_WARN("No such field in condition. %s.%s", table.name(), condition.right_attr.attribute_name);
      return RC::SCHEMA_FIELD_MISSING;
    }
    right.attr_length = field_right->len();
    right.attr_offset = field_right->offset();
    type_right = field_right->type();
      //TODO:add text 为了能找到对应data文件
      right.base_dir= strdup(table.base());
      right.table_name= strdup(table.name());
      right.attr_name= strdup(field_right->name());

    right.value = nullptr;
  } else {
    right.is_attr = false;
    right.value = condition.right_value.data;
    type_right = condition.right_value.type;

    right.attr_length = 0;
    right.attr_offset = 0;
  }

  // 校验和转换
  //  if (!field_type_compare_compatible_table[type_left][type_right]) {
  //    // 不能比较的两个字段， 要把信息传给客户端
  //    return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  //  }
  // NOTE：这里没有实现不同类型的数据比较，比如整数跟浮点数之间的对比
  // 但是选手们还是要实现。这个功能在预选赛中会出现
  //TODO: add date 对于date的比较， 应该注意判断比较的type是string， 且string是符合date的情况
  if (type_left != type_right) {
    int date_i;
    if(left.is_attr&&type_left==DATES&&(!right.is_attr)&&type_right==CHARS&&(date_i=dateToInt((char*)right.value))!=-1){
      memcpy(right.value,&date_i, sizeof(date_i));
    }else if((!left.is_attr)&&type_left==CHARS&&right.is_attr&&type_right==DATES&&(date_i=dateToInt((char*)left.value))!=-1){
      memcpy(left.value,&date_i, sizeof(date_i));
    }//TODO:add join 对多种数组类型增加判断
    else if(type_left==CHARS&&type_right==ARR_CHARS){
      type_left=ARR_CHARS;
    }else if(type_left==INTS&&type_right==ARR_INTS){
      type_left=ARR_INTS;
    }else if(type_left==FLOATS&&type_right==ARR_FLOATS){
      type_left=ARR_FLOATS;
    }else if(type_left==FLOATS&&type_right==INTS){//应对子查询需要不同类型比较
         type_left=FLOAT_INT;
    }else if(type_left==INTS&&type_right==FLOATS){//应对子查询需要不同类型比较
        type_left=INT_FLOAT;
    }//TODO: add text
    else if((type_left==TEXTS&&type_right==CHARS)||(type_left==CHARS&&type_right==TEXTS)){
        type_left=TEXTS;
    }
    else if(type_left == UNDEFINED || type_right == UNDEFINED) {
        LOG_WARN("this is a null value compare");
    }else{
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
    }
  }

    return init(left, right, type_left, condition.comp);
  }

bool DefaultConditionFilter::filter(const Record &rec) const
{
  char *left_value = nullptr;
  char *right_value = nullptr;
  int is_null = 0;

  if (left_.is_attr) {
      if(attr_type_==TEXTS){//TODO:add text 去读取相应值
          int index = *(int *)(rec.data + left_.attr_offset + sizeof(int));
          char* tmp= (char*)(malloc(TEXT_MAX_NUM + 1));
          memset(tmp,0,TEXT_MAX_NUM+1);
          readText(left_.base_dir,left_.table_name,left_.attr_name,tmp,index);
          left_value=tmp;
      }else{
          left_value = (char *)(rec.data + left_.attr_offset + sizeof(int));
          is_null = *(int *)(rec.data + left_.attr_offset);//判断属性列是否为null
      }

  } else {
    left_value = (char *)left_.value;
  }

  if (right_.is_attr) {
      if(attr_type_==TEXTS){
          int index = *(int *)(rec.data + right_.attr_offset + sizeof(int));
          char* tmp=(char *)(malloc(TEXT_MAX_NUM + 1));
          memset(tmp,0,TEXT_MAX_NUM+1);
          readText(right_.base_dir,right_.table_name,right_.attr_name,tmp,index);
          right_value=tmp;
      }else{
          right_value = (char *)(rec.data + right_.attr_offset + sizeof(int));
          is_null = *(int *)(rec.data + left_.attr_offset);
      }

  } else {
    right_value = (char *)right_.value;
  }

  //当比较符是is或者is not是特殊处理
  if (comp_op_==IS_){
        if(is_null==1 || (left_value == nullptr&&right_value== nullptr))
            return true;
        else
            return false;
  }
  if (comp_op_==IS_NOT){
        if(is_null==1 || (left_value == nullptr&&right_value== nullptr))
            return false;
        else
            return true;
  }
  //in也要特别处理空值的情况
    if (comp_op_==IN&&right_value== nullptr){//in一个空
        return false;
    }
    if(comp_op_==NOT_IN&&right_value== nullptr){
        return true;
    }
  //这里是判断null=null的情况
  if(right_value==nullptr || left_value==nullptr){
    return false;
  }
  //如果左属性或右属性哪一个为null，那么直接返回false
  if(is_null==1){
      return false;
  }

  int cmp_result = 0;
  switch (attr_type_) {
      case TEXTS://TODO: add text
    case CHARS: {  // 字符串都是定长的，直接比较
      // 按照C字符串风格来定
      cmp_result = strcmp(left_value, right_value);
    } break;
    break;
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
//      cmp_result = (int)(left - right);//不能强转为int, 例如0.2会转为0,含义出错
    float tmp=left - right;
    if(tmp<0){
        cmp_result=-1;
    }else if(tmp>0){
        cmp_result=1;
    }
    } break;
    case FLOAT_INT:{//左FLOAT 右INT
        float left = *(float *)left_value;
        int right = *(int *)right_value;
        float tmp=left - right;
        if(tmp<0){
            cmp_result=-1;
        }else if(tmp>0){
            cmp_result=1;
        }
    }break;
    case INT_FLOAT:{//左INT 右FLOAT
        int left = *(int *)left_value;
        float right = *(float *)right_value;
        float tmp=left - right;
        if(tmp<0){
            cmp_result=-1;
        }else if(tmp>0){
            cmp_result=1;
        }
    }break;
    case ARR_INTS:{
      int left = *(int *)left_value;
      size_t size = *(size_t*)right_value;//获取数组长度
      int* right=(int*)((char*)right_value+sizeof(size_t));
      for(size_t i=0;i<size;i++){
        if(left==right[i]){
          cmp_result=1;//存在相等的值
          break;
        }
          
      }
    }
    break;
    case ARR_FLOATS:{
      float left = *(float *)left_value;
      size_t size = *(size_t*)right_value;//获取数组长度
      float* right=(float*)((char*)right_value+sizeof(size_t));
      for(size_t i=0;i<size;i++){
        if(left==right[i]){
          cmp_result=1;//存在相等的值
          break;
        }
          
      }
    }
    break;
    case ARR_CHARS:{
      size_t size = *(size_t*)right_value;//获取数组长度
      char** right=(char**)((char*)right_value+sizeof(size_t));
      for(size_t i=0;i<size;i++){
        if(strcmp(left_value, right[i])){
          cmp_result=1;
          break;
        }
      }
    }
    break;
    default: {
    }
  }

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
    case IN:
      return cmp_result==1;
    case NOT_IN:
      return cmp_result!=1;
    default:
      break;
  }

  LOG_PANIC("Never should print this.");
  return cmp_result;  // should not go here
}

CompositeConditionFilter::~CompositeConditionFilter()
{
  if (memory_owner_) {
    delete[] filters_;
    filters_ = nullptr;
  }
}

RC CompositeConditionFilter::init(const ConditionFilter *filters[], int filter_num, bool own_memory)
{
  filters_ = filters;
  filter_num_ = filter_num;
  memory_owner_ = own_memory;
  return RC::SUCCESS;
}
RC CompositeConditionFilter::init(const ConditionFilter *filters[], int filter_num)
{
  return init(filters, filter_num, false);
}

RC CompositeConditionFilter::init(Table &table, const Condition *conditions, int condition_num)
{
  if (condition_num == 0) {
    return RC::SUCCESS;
  }
  if (conditions == nullptr) {
    return RC::INVALID_ARGUMENT;
  }

  RC rc = RC::SUCCESS;
  ConditionFilter **condition_filters = new ConditionFilter *[condition_num];
  for (int i = 0; i < condition_num; i++) {
    DefaultConditionFilter *default_condition_filter = new DefaultConditionFilter();
    rc = default_condition_filter->init(table, conditions[i]);
    if (rc != RC::SUCCESS) {
      delete default_condition_filter;
      for (int j = i - 1; j >= 0; j--) {
        delete condition_filters[j];
        condition_filters[j] = nullptr;
      }
      delete[] condition_filters;
      condition_filters = nullptr;
      return rc;
    }
    condition_filters[i] = default_condition_filter;
  }
  return init((const ConditionFilter **)condition_filters, condition_num, true);
}

bool CompositeConditionFilter::filter(const Record &rec) const
{

  for (int i = 0; i < filter_num_; i++) {
    if (!filters_[i]->filter(rec)) {
      return false;
    }
  }
  return true;
}
