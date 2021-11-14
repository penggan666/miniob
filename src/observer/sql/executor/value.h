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

#ifndef __OBSERVER_SQL_EXECUTOR_VALUE_H_
#define __OBSERVER_SQL_EXECUTOR_VALUE_H_

#include <string.h>

#include <string>
#include <ostream>
#include <iomanip>

class TupleValue {
public:
  TupleValue() = default;
  virtual ~TupleValue() = default;

  virtual void to_string(std::ostream &os) const = 0;
  virtual int compare(const TupleValue &other) const = 0;
  virtual void get_value(float &value) const=0;
  virtual int get_is_null() const=0;
private:
};

class IntValue : public TupleValue {
public:
  explicit IntValue(int value,int is_null) : value_(value),is_null_(is_null) {
  }

  void to_string(std::ostream &os) const override {
    if (is_null_==1){
        os << "null";
    } else {
        os << value_;
    }
  }

  int compare(const TupleValue &other) const override {
    if(is_null_!=other.get_is_null()){
        return -(is_null_-other.get_is_null());
    }else {
        if(is_null_==1)
            return 0;
        const IntValue &int_other = (const IntValue &) other;
        return value_ - int_other.value_;
    }
  }

  void get_value(float &value) const override {
      value=(float)value_;
  }

  int get_is_null() const override{
      return is_null_;
  }


private:
  int is_null_;
  int value_;
};

class FloatValue : public TupleValue {
public:
  explicit FloatValue(float value,int is_null) : value_(value),is_null_(is_null) {
  }

  void to_string(std::ostream &os) const override {
      if (is_null_==1){
          os << "null";
      } else {
          int tmpVaule=value_*100;
          os << (float)tmpVaule/100;
      }
  }

  int compare(const TupleValue &other) const override {
   if(is_null_!=other.get_is_null()){
       return -(is_null_-other.get_is_null());
    }else {
       if(is_null_==1)
           return 0;
       const FloatValue &float_other = (const FloatValue &) other;
       float result = value_ - float_other.value_;
       if (result > 0) { // 浮点数没有考虑精度问题
           return 1;
       }
       if (result < 0) {
           return -1;
       }
       return 0;
   }
  }

  void get_value(float &value) const override {
        value=value_;
  }

  int get_is_null() const override{
      return is_null_;
  }

private:
  int is_null_;
  float value_;
};

class StringValue : public TupleValue {
public:
  StringValue(const char *value, int len, int is_null) : value_(value, len),is_null_(is_null){
  }
  explicit StringValue(const char *value) : value_(value) {
  }

  void to_string(std::ostream &os) const override {
      if (is_null_==1){
          os << "null";
      } else {
          os << value_;
      }
  }

  int compare(const TupleValue &other) const override {
    if(is_null_!=other.get_is_null()){
        return -(is_null_-other.get_is_null());
    }else {
        if(is_null_==1)
            return 0;
        const StringValue &string_other = (const StringValue &) other;
        return strcmp(value_.c_str(), string_other.value_.c_str());
    }
  }

  void get_value(float &value) const override {
      value=0.0;
  }

  int get_is_null() const override{
      return is_null_;
  }

private:
  int is_null_;
  std::string value_;
};


#endif //__OBSERVER_SQL_EXECUTOR_VALUE_H_
