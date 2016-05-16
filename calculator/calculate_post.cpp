//
//  calculate.cpp
//  calculator
//
//  Created by 刘驭壬 on 16/5/16.
//  Copyright © 2016年 刘驭壬. All rights reserved.
//

#include "calculator.h"
extern set<char>valid_char_set;
extern set<char>operator_set;
extern map<char,int>operator_priority;

double calculate_two(double a, double b, string operand) {
    double result;
    if(operand == "+") {
        result = a+b;
    } else if(operand == "-") {
        result = a-b;
    } else if(operand == "*") {
        result = a*b;
    } else if(operand == "/") {
        if(b==0) {
            cout<<"除数不能为0"<<endl;
            exit(-1);
        }
        result = a/b;
    } else if(operand == "%") {
        result = (static_cast<int>(a)) % (static_cast<int>(b));
    } else if(operand == "^") {
        result = pow(a, b);
    }
    return result;
}

double calculate_post(queue<string>& post) {
    stack<double> result_stack;
    while(!post.empty()) {
        string temp = post.front();
        post.pop();
        if(is_operator(temp[0])) { //是操作符
            if(result_stack.size()<2) {
                cout<<"表达式错误"<<endl;
                exit(-1);
            }
            //从栈中取出两个元素，计算并将结果压入栈中
            double operand2 = result_stack.top();
            result_stack.pop();
            double operand1 = result_stack.top();
            result_stack.pop();
            
            double m = calculate_two(operand1, operand2, temp);
            result_stack.push(m);
        } else { //操作数
            double temp_operand = atof(temp.c_str());
            result_stack.push(temp_operand);
        }
    }
    return result_stack.top();
}