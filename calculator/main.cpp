//
//  main.cpp
//  calculator
//
//  Created by 刘驭壬 on 16/5/14.
//  Copyright © 2016年 刘驭壬. All rights reserved.
//

#include <iostream>
#include "calculator.h"
using namespace std;

set<char>valid_char_set;
set<char>operator_set;
map<char,int>operator_priority;


int main(int argc, const char * argv[]) {
    cout<<"calculator star"<<endl;
    string infix;
    string temp1;//保存去处括号后的结果
    string after_prefix;
    queue<string>post_fix;
    queue<string>temp_queue;
    double result;
    init_valid_char_set();
    init_operator_set();
    init_operator_priority();
    while(1){
        while(!post_fix.empty()){
            post_fix.pop();
        }
        //p判断括号是否配对
        cout<<"请输入要求表达式（中值表达式）"<<endl;
        getline(cin,infix);
        if(!bracket_paired(infix)){
            cout<<"输入表达式子括号不配对，请重新输入"<<endl;
            continue;
        }
        
        //判断表达式是否存在不能识别的操作符
        temp1=delete_space(infix);
        if(!if_valid(temp1)){
            continue;
        }
        
        //处理＋－作为一元操作符的情况
        after_prefix=handle_1_operator(temp1);
        
        //转换为后缀表达式
        post_fix=infix_to_post(after_prefix);
       /* cout<<"后缀表达式为："<<endl;
        temp_queue=post_fix;
        while(!temp_queue.empty()){
            cout<<temp_queue.front()<<" ";
            temp_queue.pop();
        }
        cout<<endl;
        */
        //从后缀表达式计算结果
        result=calculate_post(post_fix);
        cout<<"计算结果为："<<result<<endl;
    }
    return 0;
}
