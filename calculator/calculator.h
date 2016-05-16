//
//  Header.h
//  calculator
//
//  Created by 刘驭壬 on 16/5/14.
//  Copyright © 2016年 刘驭壬. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <math.h>
using namespace std;

struct return_value{
    bool valid;
    string result;
};

bool is_operator(char ch);//判断是否是操作符
int compare_priority(char a,char b);//比较两个操作符的优先级
bool bracket_paired(string infix);//判断输入表达式中的括号是否配对
bool if_valid(string infix);//判断表达式是否存在无法识别的操作符
void init_valid_char_set();//初始化有效字符集
void init_operator_set();//初始化操作符集
void init_operator_priority();//初始化操作符优先级集合
string delete_space(string infix);//预处理函数消除空格
string handle_1_operator(string infix);//处理一元操作符
queue<string>infix_to_post(string infix);//将前缀表达式转换成后缀表达式的函数
double bi_calculate(double a,double b,char operand);//计算两个操作数在操作符运算后的结果
double calculate_post(queue<string>&post);//对后缀表达式进行求值


#endif /* Header_h */
