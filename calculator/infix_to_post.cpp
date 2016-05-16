//
//  function.cpp
//  calculator
//
//  Created by 刘驭壬 on 16/5/15.
//  Copyright © 2016年 刘驭壬. All rights reserved.
//

#include "calculator.h"
extern set<char>valid_char_set;
extern set<char>operator_set;
extern map<char,int>operator_priority;


queue<string> infix_to_post(string infix) {
    queue<string> postfix;//后缀表达式队列
    stack<char> operator_stack;//转换过程中，用来存储操作符的栈
    
    set<char> valid_operand_set;//操作数 中的字符
    for(int i=0; i<=9; i++) {
        valid_operand_set.insert(i+'0');
    }
    valid_operand_set.insert('.');
    valid_operand_set.insert('e');
    valid_operand_set.insert('E');
    
    for(int i=0; i<infix.size(); i++) {
      //  cout<<endl;
       // char ch = infix[i];
      //  cout<<"序号："<<"  "<<i<<"  字符：  "<<ch<<endl;
        if(infix[i]=='(') {//左括号
            operator_stack.push(infix[i]);
        } else if(infix[i]==')') {//右括号
            while(!operator_stack.empty() && operator_stack.top()!='(') {
                postfix.push(string(1, operator_stack.top()));
                operator_stack.pop();
            }
            operator_stack.pop();//将"("出栈
        } else if(is_operator(infix[i]) == true) { //是操作符（不包含 左、右括号）
            if(operator_stack.empty()) { //操作符栈为空
                operator_stack.push(infix[i]);
                continue;
            }
            
            //操作符栈非空
            char top_stack = operator_stack.top();
            //将栈中“较高和相等”优先级的操作符放到 后缀表达式中。
            //终止条件为：当前操作符>栈顶操作符优先级，或优先级相等、但栈顶操作符的结合性是“从右向左”。
            while(compare_priority(infix[i], top_stack)<=0) {
                //优先级相等，但栈顶操作符结合性为从右向左，这里特指'^'
                if(compare_priority(infix[i], top_stack)==0 && infix[i]=='^') {   //因为'^'的结合性从右向左，所以单独处理
                    break;
                }
                //当前操作符<=栈顶操作符优先级，当前操作符结合性为从左到右
                postfix.push(string(1, top_stack));
                operator_stack.pop();
                if(!operator_stack.empty()) {
                    top_stack = operator_stack.top();
                } else {
                    break;
                }
                
            }
            //将当前操作符入栈
            operator_stack.push(infix[i]);
        } else {//操作数
            string current_operator;
            int j=i;
            while(valid_operand_set.find(infix[j]) != valid_operand_set.end()) {
                current_operator += infix[j];
                ++j;
            }
            postfix.push(current_operator);
            i=j-1;//因为for循环，每次都会执行i++
        }
        
        //打印处理过程
        //cout<<"当前栈顶： "<<(operator_stack.empty() ?' ': operator_stack.top())<<endl;
        queue<string> temp_queue = postfix;
       //cout<<"当前后缀表达式： ";
        while(temp_queue.size()>0) {
           // cout<<temp_queue.front()<<"  ";
            temp_queue.front();
            temp_queue.pop();
        }
      //  cout<<endl;
    
    }
    //最后将栈中内容全部取出来
    while(!operator_stack.empty()) {
        postfix.push(string(1, operator_stack.top()));
        operator_stack.pop();
    }
    
    return postfix;  
}

