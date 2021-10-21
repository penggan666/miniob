//
// Created by penggan on 2021/10/21.
//
#include "tools/simple_tool.h"
bool Check_date(int w_year,int w_month,int w_date)
{
    int Month_buf[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };               //月份修正表

    if (w_month==2)                                                             //闰年2月+1天
        (((w_year%4==0)&&(w_year%100!=0))||(w_year%400==0))?Month_buf[1]+=1:Month_buf[1];

    if (w_month>12||w_month<1||w_date>Month_buf[w_month-1]||w_date<1)           //判断月份日期是否合法
        return false;

    return true;
}

int dateToInt(char str[])
{
    std::string text=std::string(str);
    std::regex  pattern("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2})");

    std::smatch results;
    int d[3];
    if ( regex_match(text, results, pattern) ) {
        std::smatch::iterator it = results.begin();
        int i = 0;
        it++;
        for(; it != results.end(); ++it){
            d[i]=stoi(*it);
            i++;
        }

    } else {
        return -1;
    }
    if(!Check_date(d[0],d[1],d[2])){
        return -1;
    }
    return d[0]*10000+d[1]*100+d[2];

}

