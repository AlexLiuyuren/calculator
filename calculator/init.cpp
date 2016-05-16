//
//  init.cpp
//  calculator
//
//  Created by 刘驭壬 on 16/5/16.
//  Copyright © 2016年 刘驭壬. All rights reserved.
//

#include "calculator.h"
extern set<char>valid_char_set;
extern set<char>operator_set;
extern map<char,int>operator_priority;

void init_operator_set(){
    operator_set.insert('+');
    operator_set.insert('-');
    operator_set.insert('*');
    operator_set.insert('/');
    operator_set.insert('%');
    operator_set.insert('^');
}
void init_operator_priority(){
    operator_priority['+']=1;
    operator_priority['-']=1;
    operator_priority['*']=2;
    operator_priority['/']=2;
    operator_priority['%']=2;
    operator_priority['^']=3;
}

void init_valid_char_set(){
    int i;
    for(i=0;i<10;i++){
        valid_char_set.insert(i+'0');
    }
    valid_char_set.insert('+');
    valid_char_set.insert('-');
    valid_char_set.insert('*');
    valid_char_set.insert('/');
    valid_char_set.insert('%');
    valid_char_set.insert('^');
    valid_char_set.insert('.');
    valid_char_set.insert('e');
    valid_char_set.insert('E');
    valid_char_set.insert('(');
    valid_char_set.insert(')');
}
