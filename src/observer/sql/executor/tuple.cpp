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
// Created by Wangyunlai on 2021/5/14.
//
#include <iostream>
#include <iomanip>

#include "sql/executor/tuple.h"
#include "storage/common/table.h"
#include "common/log/log.h"

Tuple::Tuple(const Tuple &other) {
  LOG_PANIC("Copy constructor of tuple is not supported");
  exit(1);
}

Tuple::Tuple(Tuple &&other) noexcept : values_(std::move(other.values_)) {
}

Tuple & Tuple::operator=(Tuple &&other) noexcept {
  if (&other == this) {
    return *this;
  }

  values_.clear();
  values_.swap(other.values_);
  return *this;
}

Tuple::~Tuple() {
}

// add (Value && value)
void Tuple::add(TupleValue *value) {
  values_.emplace_back(value);
}
void Tuple::add(const std::shared_ptr<TupleValue> &other) {
  values_.emplace_back(other);
}
void Tuple::add(int value,int is_null) {
  add(new IntValue(value,is_null));
}

void Tuple::add(float value,int is_null) {
  add(new FloatValue(value,is_null));
}

void Tuple::add(const char *s, int len,int is_null) {
  add(new StringValue(s, len, is_null));
}

////////////////////////////////////////////////////////////////////////////////

std::string TupleField::to_string() const {
  return std::string(table_name_) + "." + field_name_ + std::to_string(type_);
}

////////////////////////////////////////////////////////////////////////////////
void TupleSchema::from_table(const Table *table, TupleSchema &schema, int aggregate_name) {
  const char *table_name = table->name();
  const TableMeta &table_meta = table->table_meta();
  const int field_num = table_meta.field_num();
  for (int i = 0; i < field_num; i++) {
    const FieldMeta *field_meta = table_meta.field(i);
    if (field_meta->visible()) {
      schema.add(field_meta->type(), table_name, field_meta->name(),aggregate_name);
    }
  }
}

void TupleSchema::add(AttrType type, const char *table_name, const char *field_name, int aggregate_name) {
  fields_.emplace_back(type, table_name, field_name, aggregate_name);
}

void TupleSchema::add_if_not_exists(AttrType type, const char *table_name, const char *field_name, int aggregate_name) {
  for (const auto &field: fields_) {
    if (0 == strcmp(field.table_name(), table_name) &&
        0 == strcmp(field.field_name(), field_name) &&
        field.aggregate_name() == aggregate_name) {
      return;
    }
  }

  add(type, table_name, field_name,aggregate_name);
}
//TODO: add join add_if_not_exists_for_join
bool TupleSchema::add_if_not_exists_for_join(AttrType type, const char *table_name, const char *field_name) {
  for (const auto &field: fields_) {
    if (0 == strcmp(field.table_name(), table_name) &&
        0 == strcmp(field.field_name(), field_name)) {
      return false;
    }
  }

  //add(type, table_name, field_name);
  return true;
}

void TupleSchema::append(const TupleSchema &other) {
  fields_.reserve(fields_.size() + other.fields_.size());
  for (const auto &field: other.fields_) {
    fields_.emplace_back(field);
  }
}

int TupleSchema::index_of_field(const char *table_name, const char *field_name) const {
  const int size = fields_.size();
  for (int i = 0; i < size; i++) {
    const TupleField &field = fields_[i];
    if (0 == strcmp(field.table_name(), table_name) && 0 == strcmp(field.field_name(), field_name)) {
      return i;
    }
  }
  return -1;
}

void TupleSchema::print(std::ostream &os) const {
  if (fields_.empty()) {
    os << "No schema";
    return;
  }

  // 判断有多张表还是只有一张表
  std::set<std::string> table_names;
  for (const auto &field: fields_) {
    table_names.insert(field.table_name());
  }
  //TODO: add join
  for (std::vector<TupleField>::const_iterator iter = fields_.begin(), end = --fields_.end();
       iter != end; ++iter) {
    if (iter->aggregate_name()!=AGG_NO){
        os << iter->aggregate_name_str() << "(";
    }
    if (table_names.size() > 1) {
      os << iter->table_name() << ".";
    }
    os << iter->field_name();
    if (iter->aggregate_name()!=AGG_NO){
        os << ")";
    }
    os << " | ";
  }

  if(fields().back().aggregate_name()!=AGG_NO){
      os << fields().back().aggregate_name_str() << "(";
  }
  if (table_names.size() > 1) {
    os << fields_.back().table_name() << ".";
  }
  os << fields_.back().field_name();
  if(fields().back().aggregate_name()!=AGG_NO){
      os << ")";
  }
  os << std::endl;
}
//TODO: add join schema_print_rm_tmp 去掉临时列
void TupleSchema::print_rm_tmp(std::ostream &os,std::vector<int>& real_column)const{
  if (fields_.empty()) {
    os << "No schema";
    return;
  }
  int i;
  for(i=0;i<real_column.size()-1;i++){
      if (fields_[real_column[i]].aggregate_name()!=AGG_NO){
          os << fields_[real_column[i]].aggregate_name_str() << "(";
      }
      os << fields_[real_column[i]].table_name() << ".";
      os << fields_[real_column[i]].field_name();
      if (fields_[real_column[i]].aggregate_name()!=AGG_NO){
          os << ")";
      }
      os << " | ";
  }
  if (fields_[real_column[i]].aggregate_name()!=AGG_NO){
      os << fields_[real_column[i]].aggregate_name_str() << "(";
  }
  os << fields_[real_column[i]].table_name() <<".";
  os << fields_[real_column[i]].field_name();
  if (fields_[real_column[i]].aggregate_name()!=AGG_NO){
    os << ")";
  }
  os << std::endl;
}


/////////////////////////////////////////////////////////////////////////////
TupleSet::TupleSet(TupleSet &&other) : tuples_(std::move(other.tuples_)), schema_(other.schema_){
  other.schema_.clear();
}

TupleSet &TupleSet::operator=(TupleSet &&other) {
  if (this == &other) {
    return *this;
  }

  schema_.clear();
  schema_.append(other.schema_);
  other.schema_.clear();

  tuples_.clear();
  tuples_.swap(other.tuples_);
  return *this;
}

void TupleSet::add(Tuple &&tuple) {
  tuples_.emplace_back(std::move(tuple));
}

void TupleSet::clear() {
  tuples_.clear();
  schema_.clear();
}

void TupleSet::sortTuple(int i) {
    for (int j=0;j<tuples_.size()-1;j++){
        for (int k=0;k<tuples_.size()-1-j;k++){
            if (tuples_[k].get(i).compare(tuples_[k+1].get(i))>0){
                std::swap(tuples_[k],tuples_[k+1]);
            }
        }
    }
}
int compare_AscOrDesc(const TupleValue& left,const TupleValue& right,bool isAsc){
    if(isAsc){
        return left.compare(right);
    }else{
        return -left.compare(right);
    }
}
void TupleSet::sortTupleByOrder(const std::vector<int> &fieldIndex, const std::vector<bool> & isAsc){
  for (int j=0;j<tuples_.size()-1;j++){
        for (int k=0;k<tuples_.size()-1-j;k++){
            Tuple& left=tuples_[k];
            Tuple& right=tuples_[k+1];
            for(size_t i=0;i<fieldIndex.size();i++){
                int fi=fieldIndex[i];
                int res=compare_AscOrDesc(left.get(fi),right.get(fi),isAsc[i]);
                if(res==0)continue;
                if(res>0){
                    std::swap(left,right);
                }
                break;
            }
        }
    }
}
TupleSet TupleSet::groupbyTuple(const std::vector<int> &fieldIndex) {
    TupleSet result;
    TupleSchema tupleSchema;
    Tuple tuple;
    std::vector<TupleField> tuple_fileds=schema_.fields();
    std::vector<bool> isAsc;
    int set_schema=0;
    //先对所有tuple按照group by字段进行排序
    for (int i=0;i<fieldIndex.size();i++)
        isAsc.push_back(true);
    sortTupleByOrder(fieldIndex,isAsc);
    //将不同group字段放入到不同的tupleset中
    TupleSet tupleset;
    tupleset.set_schema(schema_);
    for (int i=0;i<tuples_.size();i++){
        int i1=i+1;
        int allequal=1;
        if (i1<tuples_.size()){
            for (int j=0;j<fieldIndex.size();j++){
                int fi = fieldIndex[j];
                if(tuples_[i1].get(fi).compare(tuples_[i].get(fi))!=0){
                    allequal=0;
                }
            }
        }
        std::vector<std::shared_ptr<TupleValue>> tuplevalues=tuples_[i].values();
        Tuple tuple1;
        for(int m=0;m<tuplevalues.size();m++)
            tuple1.add(tuplevalues[m]);
        tupleset.tuples_.emplace_back(std::move(tuple1));
        if(allequal==0||i==tuples_.size()-1){
            //对当前分组做一次聚合
            for(int k=0;k<tuple_fileds.size();k++){
                switch (tuple_fileds[k].aggregate_name()) {
                    case AGG_MIN:{
                        tupleSchema.add(tuple_fileds[k].type(), tuple_fileds[k].table_name(), tuple_fileds[k].field_name(), AGG_MIN);
                        if (tupleset.size()>0)
                            tuple.add(tupleset.minTuple(k)[k]);
                    }
                        break;
                    case AGG_MAX: {
                        tupleSchema.add(tuple_fileds[k].type(), tuple_fileds[k].table_name(), tuple_fileds[k].field_name(), AGG_MAX);
                        if (tupleset.size()>0)
                            tuple.add(tupleset.maxTuple(k)[k]);
                    }
                        break;
                    case AGG_COUNT:{
                        tupleSchema.add(INTS, tuple_fileds[k].table_name(), tuple_fileds[k].field_name(), AGG_COUNT);
                        tuple.add(tupleset.countTupleColumn(k),0);
                    }
                        break;
                    case AGG_AVG:{
                        tupleSchema.add(FLOATS, tuple_fileds[k].table_name(),tuple_fileds[k].field_name(), AGG_AVG);
                        if (tupleset.size()>0){
                            float result = tupleset.avgTuple(k);
                            if (result==-1)
                                tuple.add(result,1);
                            else
                                tuple.add(result,0);
                        }
                    }
                        break;
                    case AGG_NO: {
                        tupleSchema.add(tuple_fileds[k].type(), tuple_fileds[k].table_name(),
                                        tuple_fileds[k].field_name(), AGG_NO);
                        tuple.add(tuples_[i].values()[k]);
                    }
                        break;
                }
            }
            if (set_schema==0) {
                result.set_schema(tupleSchema);
                set_schema=1;
            }
            result.add(std::move(tuple));
            tupleset.tuples_.clear();
        }
    }
    return result;
}

const std::vector<std::shared_ptr<TupleValue>> TupleSet::minTuple(int i) {
    sortTuple(i);
    for (int j=0;j<tuples_.size();j++){
        if (tuples_[j].get(i).get_is_null()==0){
            return tuples_[j].values();
        }
    }
    return tuples_.front().values();
}

const std::vector<std::shared_ptr<TupleValue>> TupleSet::maxTuple(int i) {
    sortTuple(i);
    return tuples_.back().values();
}

int TupleSet::countTupleStar() {
    return tuples_.size();
}

int TupleSet::countTupleColumn(int i) {
    int sum=0;
    for (int j=0;j<tuples_.size();j++){
        if (tuples_[j].get(i).get_is_null()==0){
            sum+=1;
        }
    }
    return sum;
}

float TupleSet::avgTuple(int i) {
    float sum=0;
    float value=0;
    int all_null=1;
    for (int j=0;j<tuples_.size();j++){
        if (tuples_[j].get(i).get_is_null()==0) {
            all_null=0;
            tuples_[j].get(i).get_value(value);
            sum += value;
        }
    }
    if(tuples_.size()!=0&&all_null==1){
        return -1;
    }
    return sum/countTupleColumn(i);
}

void TupleSet::print(std::ostream &os) const {
  if (schema_.fields().empty()) {
    LOG_WARN("Got empty schema");
    return;
  }

  schema_.print(os);

  for (const Tuple &item : tuples_) {
    const std::vector<std::shared_ptr<TupleValue>> &values = item.values();
    for (std::vector<std::shared_ptr<TupleValue>>::const_iterator iter = values.begin(), end = --values.end();
          iter != end; ++iter) {
      (*iter)->to_string(os);
      os << " | ";
    }
    values.back()->to_string(os);
    os << std::endl;
  }
}
//TODO: add join  去掉临时列
void TupleSet::print_rm_tmp(std::ostream &os,std::vector<int>& real_column) const{
  //先遍历获得一个真实列的索引集合, 比如0,2,3,4 ,然后根据上边的逻辑遍历集合
  if (schema_.fields().empty()) {
    LOG_WARN("Got empty schema");
    return;
  }

  schema_.print_rm_tmp(os,real_column);
  
  for (const Tuple &item : tuples_) {
    const std::vector<std::shared_ptr<TupleValue>> &values = item.values();
    int i;
    for(i=0;i<real_column.size()-1;i++){
      std::shared_ptr<TupleValue> tv=values[real_column[i]];
      tv->to_string(os);
      os << " | ";
  }
    values[real_column[i]]->to_string(os);
    os << std::endl;
  }
}
void TupleSet::set_schema(const TupleSchema &schema) {
  schema_ = schema;
}

const TupleSchema &TupleSet::get_schema() const {
  return schema_;
}

bool TupleSet::is_empty() const {
  return tuples_.empty();
}

int TupleSet::size() const {
  return tuples_.size();
}

const Tuple &TupleSet::get(int index) const {
  return tuples_[index];
}

const std::vector<Tuple> &TupleSet::tuples() const {
  return tuples_;
}

/////////////////////////////////////////////////////////////////////////////
TupleRecordConverter::TupleRecordConverter(Table *table, TupleSet &tuple_set) :
      table_(table), tuple_set_(tuple_set){
}

void TupleRecordConverter::add_record(const char *record) {
  const TupleSchema &schema = tuple_set_.schema();
  Tuple tuple;
  const TableMeta &table_meta = table_->table_meta();
  for (const TupleField &field : schema.fields()) {
    const FieldMeta *field_meta = table_meta.field(field.field_name());
    assert(field_meta != nullptr);
    int is_null = *(int*)(record + field_meta->offset());
    switch (field_meta->type()) {
      case INTS: {
          int value = *(int*)(record + field_meta->offset() + sizeof(int));
        tuple.add(value,is_null);
      }
      break;
      case FLOATS: {
        float value = *(float *)(record + field_meta->offset() + sizeof(int));
        tuple.add(value,is_null);
      }
      break;
      case CHARS: {
        const char *s = record + field_meta->offset() + sizeof(int);  // 现在当做Cstring来处理
        tuple.add(s, strlen(s),is_null);
      }
      break;
      //TODO: add date select展示数据
      case DATES:{
        //取出int数据
        int value = *(int*)(record + field_meta->offset() + sizeof(int));
        //转化位string
        int year=value/10000;
        int month=(value%10000)/100;
        int day=value%100;
        std::stringstream ss;
	      ss << year << "-" << std::setw(2) << std::setfill('0') << month<<"-"<<std::setw(2) << std::setfill('0')<<day;
        const char *s=ss.str().c_str();
        tuple.add(s, strlen(s),is_null);//TODO:join 注意tuple阶段的date类型会被初始化位StringValue
      }
      break;
      default: {
        LOG_PANIC("Unsupported field type. type=%d", field_meta->type());
      }
    }
  }

  tuple_set_.add(std::move(tuple));
}


