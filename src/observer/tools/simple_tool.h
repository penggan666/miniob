//
// Created by penggan on 2021/10/21.
//

#include <regex>
#include <string>
#include "storage/common/meta_util.h"
#ifndef MINIDB_SIMPLE_TOOL_H
#define MINIDB_SIMPLE_TOOL_H
    #define TEXT_MAX_NUM 4096
    bool Check_date(int w_year,int w_month,int w_date);
    int dateToInt(char str[]);
    int insertText(const char *base_dir, const char *table_name,const char* text_name,const char* text);
    bool readText(const char *base_dir, const char *table_name,const char* text_name,void * res,int len);
#endif //MINIDB_SIMPLE_TOOL_H
