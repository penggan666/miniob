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

#ifndef __OBSERVER_SQL_EXECUTOR_TUPLE_H_
#define __OBSERVER_SQL_EXECUTOR_TUPLE_H_

#include <memory>
#include <vector>
#include <algorithm>

#include "sql/parser/parse.h"
#include "sql/executor/value.h"
#include "tools/simple_tool.h"


class Table;

class Tuple {
public:
  Tuple() = default;

  Tuple(const Tuple &other);

  ~Tuple();

  Tuple(Tuple &&other) noexcept ;
  Tuple & operator=(Tuple &&other) noexcept ;

  void add(TupleValue *value);
  void add(const std::shared_ptr<TupleValue> &other);
  void add(int value,int is_null);
  void add(float value,int is_null);
  void add(const char *s, int len,int is_null);

  const std::vector<std::shared_ptr<TupleValue>> &values() const {
    return values_;
  }

  int size() const {
    return values_.size();
  }

  const TupleValue &get(int index) const {
    return *values_[index];
  }

  const std::shared_ptr<TupleValue> &get_pointer(int index) const {
    return values_[index];
  }

private:
  std::vector<std::shared_ptr<TupleValue>>  values_;
};

class TupleField {
public:
  TupleField(AttrType type, const char *table_name, const char *field_name, int aggregate_name) :
          type_(type), table_name_(table_name), field_name_(field_name), aggregate_name_(aggregate_name){
  }

  AttrType  type() const{
    return type_;
  }

  const char *table_name() const {
    return table_name_.c_str();
  }
  const char *field_name() const {
    return field_name_.c_str();
  }
  const int aggregate_name() const{
      return aggregate_name_;
  }
  const char *aggregate_name_str() const{
      switch (aggregate_name_) {
          case AGG_COUNT_STAR:
          case AGG_COUNT:
              return "COUNT";
          case AGG_MAX:
              return "MAX";
          case AGG_MIN:
              return "MIN";
          case AGG_AVG:
              return "AVG";
      }
  }

  std::string to_string() const;
private:
  AttrType  type_;
  std::string table_name_;
  std::string field_name_;
  int aggregate_name_;
};

class TupleSchema {
public:
  TupleSchema() = default;
  ~TupleSchema() = default;

  void add(AttrType type, const char *table_name, const char *field_name, int aggregate_name);
  void add_if_not_exists(AttrType type, const char *table_name, const char *field_name, int aggregate_name);
  bool add_if_not_exists_for_join(AttrType type, const char *table_name, const char *field_name);
  // void merge(const TupleSchema &other);
  void append(const TupleSchema &other);

  const std::vector<TupleField> &fields() const {
    return fields_;
  }

  const TupleField &field(int index) const {
    return fields_[index];
  }

  int index_of_field(const char *table_name, const char *field_name) const;
  void clear() {
    fields_.clear();
  }

  void print(std::ostream &os) const;
  void print_rm_tmp(std::ostream &os,std::vector<int>& tmp_column) const;
public:
  static void from_table(const Table *table, TupleSchema &schema, int aggregate_name);
private:
  std::vector<TupleField> fields_;
};

class TupleSet {
public:
  TupleSet() = default;
  TupleSet(TupleSet &&other);
  explicit TupleSet(const TupleSchema &schema) : schema_(schema) {
  }
  TupleSet &operator =(TupleSet &&other);

  ~TupleSet() = default;

  void set_schema(const TupleSchema &schema);

  const TupleSchema &get_schema() const;

  void add(Tuple && tuple);

  void clear();

  //TODO: 根据某一个属性列对tuple进行排序
  void sortTuple(int i);
  //TODO: 取tuple某列的最大值
  const std::vector<std::shared_ptr<TupleValue>> maxTuple(int i);
  //TODO: 取tuple某列的最小值
  const std::vector<std::shared_ptr<TupleValue>> minTuple(int i);
  //TODO: 取tuple的某列的平均值
  float avgTuple(int i);
  //TODO: 取tuple的数量
  int countTupleStar();
  int countTupleColumn(int i);

  //TODO: add order 根据多列进行排序
  void sortTupleByOrder(const std::vector<int> &fieldIndex, const std::vector<bool> & isAsc);
  TupleSet groupbyTuple(const std::vector<int> &fieldIndex);
  bool is_empty() const;
  int size() const;
  const Tuple &get(int index) const;
  const std::vector<Tuple> &tuples() const;

  void print(std::ostream &os) const;
  void print_rm_tmp(std::ostream &os,std::vector<int>& real_column) const;
public:
  const TupleSchema &schema() const {
    return schema_;
  }
private:
  std::vector<Tuple> tuples_;
  TupleSchema schema_;
};

class TupleRecordConverter {
public:
  TupleRecordConverter(Table *table, TupleSet &tuple_set);

  void add_record(const char *record);
private:
  Table *table_;
  TupleSet &tuple_set_;
};

#endif //__OBSERVER_SQL_EXECUTOR_TUPLE_H_
