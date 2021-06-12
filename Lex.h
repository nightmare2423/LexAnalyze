#pragma once
#include "basic.h"


char* place;    //指向输入串的位置
char c_new;     //最新读入的字符
string token;    //存放已经读入的字符
map<string, int> key_table;//保留字表
map<string, int> sy_table;//符号表
map<int, int> cs_table;//常数表

void Getchar();    //读入一个字符到c_new中
void Getnbc();     //读入非空白字符检查变量c_new中的字符是否为空白，若是则读入下一个直到非空白

void concat();     //连接字符串，将c_new的字符连接到token数组末尾

bool Isletter();   //判断c_new是不是字母
bool Isdigit();    //判断c_new是不是

void retract();    //回退字符，将刚刚读入的字符

void make_table(); //构造符号表
int reserve();     //处理保留字的函数，对存放在token中的字符串
void symbol();      //处理标识符的函数，对token中的字符串查符号榜，若查到，则返回位置编号
int constant();    //常数存入常数表的函数，将数字串转换为二进制整数存入到常数表中，并返回位置编号


void Getchar() {             //读入字符
	c_new = *place;
	place++;
}

void Getnbc() {           //读入非空白字符
	while (c_new == ' ') {
		c_new = *place;
		place++;
	}
}

void concat() {         //连接字符串
	token.push_back(c_new);
}

bool Isletter() {     //判断是否为字母
	if (c_new >= 'A' && c_new <= 'Z')return true;
	else if (c_new >= 'a' && c_new <= 'z')return true;
	else return false;
}

bool Isdigit() {          //判断是否为数字
	if (c_new >= '0' && c_new <= '9')return true;
	else return false;
}

void retract() {   //回退，指针退位并置最新为空白
	place--;
	c_new = ' ';
}

void make_table() {   //初始化保留字表

	for (int i = 0; i < 9; i++)
		key_table[dic[i]] = i + 1;
}

int reserve() {    //处理保留字，若查到则返回类型编码，否则返回10（标识符）
	auto result = key_table.find(token);
	if (result != key_table.end()) {
		return result->second;
	}
	else {
		symbol();
		return 10;
	}
}


void symbol() {      //将标识符插入到表中
	auto result = sy_table.find(token);
	if (result == sy_table.end()) {
		int num = 1 + sy_table.size();
		sy_table[token] = num;
	}
	return;
}

int constant() {       //将常数存入常量表并返回11
	try {
		stoi(token);
	}
	catch (exception err) {
		return -4;
	}
	auto result = cs_table.find(stoi(token));
	if (result == cs_table.end()) {
		int num = 1 + cs_table.size();
		cs_table[stoi(token)] = num;
	}
	return 11;
}