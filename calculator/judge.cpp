//
//  judge.cpp
//  calculator
//
//  Created by 刘驭壬 on 16/5/16.
//  Copyright © 2016年 刘驭壬. All rights reserved.
//
#include "calculator.h"
extern set<char>valid_char_set;
extern set<char>operator_set;
extern map<char,int>operator_priority;

bool is_operator(char ch){
    return operator_set.find(ch)!=operator_set.end();
}

int compare_priority(char a,char b){
    return operator_priority[a]-operator_priority[b];
}

bool bracket_paired(string infix){
    stack<char>bracket;
    int i;
    for(i=0;i<infix.size();i++){
        if(infix[i]=='('){
            bracket.push('(');
        }
        else if (infix[i]==')'){
            if (infix.empty()) {
                cout<<"缺少左括号，表达式输入错误"<<endl;
                return false;
            }
            bracket.pop();
        }
    }
    if(!bracket.empty()){
        cout<<"缺少右括号,表达式输入错误"<<endl;
        return false;
    }
    init_valid_char_set();
    return true;
}

bool if_valid(string infix){
    int i;
    for (i=0; i<infix.size(); i++) {
        if(valid_char_set.find(infix[i])==valid_char_set.end()){
            cout<<"无法识别部分您输入的操作符"<<endl;
            return false;
        }
    }
    return true;
}
