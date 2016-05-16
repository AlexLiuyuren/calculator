//
//  pretreat.cpp
//  calculator
//
//  Created by 刘驭壬 on 16/5/16.
//  Copyright © 2016年 刘驭壬. All rights reserved.
//

#include"calculator.h"

string delete_space(string infix){
    size_t mark;
    string result=infix;
    while((mark=infix.find(" "))!=string::npos){
        result.erase(mark);
    }
   // cout<<"去除空格后的表达式为:"<<result<<endl;
    return result;
}

string handle_1_operator(string infix){
    string result=infix;
    for(int i=0; i<result.size(); i++) {
        char temp=result[i];
        if(temp!='+'&&temp!='-') {
            continue;
        }
        if(i==0) {
            result.insert(i,1,'0');
        } else if(i-1>=0 && !isdigit(result[i-1]) && result[i-1]!=')') {
            result.insert(i, "(0");
            int j = i+3;
            int bracket_count=0;
            for(; j<result.size(); j++) {
                if(isdigit(result[j]) || result[j]=='.') {
                    continue;
                } else if(result[j]=='(') {
                    ++bracket_count;
                } else if(result[j]==')') {
                    if((--bracket_count) == 0) {
                        break;
                    }
                } else if(bracket_count==0) {
                    break;
                }
            }
            i = j;
            result.insert(j, ")");
        }
    }
    return result;
}

