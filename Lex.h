#pragma once
#include "basic.h"


char* place;    //ָ�����봮��λ��
char c_new;     //���¶�����ַ�
string token;    //����Ѿ�������ַ�
map<string, int> key_table;//�����ֱ�
map<string, int> sy_table;//���ű�
map<int, int> cs_table;//������

void Getchar();    //����һ���ַ���c_new��
void Getnbc();     //����ǿհ��ַ�������c_new�е��ַ��Ƿ�Ϊ�հף������������һ��ֱ���ǿհ�

void concat();     //�����ַ�������c_new���ַ����ӵ�token����ĩβ

bool Isletter();   //�ж�c_new�ǲ�����ĸ
bool Isdigit();    //�ж�c_new�ǲ���

void retract();    //�����ַ������ոն�����ַ�

void make_table(); //������ű�
int reserve();     //�������ֵĺ������Դ����token�е��ַ���
void symbol();      //�����ʶ���ĺ�������token�е��ַ�������Ű����鵽���򷵻�λ�ñ��
int constant();    //�������볣����ĺ����������ִ�ת��Ϊ�������������뵽�������У�������λ�ñ��


void Getchar() {             //�����ַ�
	c_new = *place;
	place++;
}

void Getnbc() {           //����ǿհ��ַ�
	while (c_new == ' ') {
		c_new = *place;
		place++;
	}
}

void concat() {         //�����ַ���
	token.push_back(c_new);
}

bool Isletter() {     //�ж��Ƿ�Ϊ��ĸ
	if (c_new >= 'A' && c_new <= 'Z')return true;
	else if (c_new >= 'a' && c_new <= 'z')return true;
	else return false;
}

bool Isdigit() {          //�ж��Ƿ�Ϊ����
	if (c_new >= '0' && c_new <= '9')return true;
	else return false;
}

void retract() {   //���ˣ�ָ����λ��������Ϊ�հ�
	place--;
	c_new = ' ';
}

void make_table() {   //��ʼ�������ֱ�

	for (int i = 0; i < 9; i++)
		key_table[dic[i]] = i + 1;
}

int reserve() {    //�������֣����鵽�򷵻����ͱ��룬���򷵻�10����ʶ����
	auto result = key_table.find(token);
	if (result != key_table.end()) {
		return result->second;
	}
	else {
		symbol();
		return 10;
	}
}


void symbol() {      //����ʶ�����뵽����
	auto result = sy_table.find(token);
	if (result == sy_table.end()) {
		int num = 1 + sy_table.size();
		sy_table[token] = num;
	}
	return;
}

int constant() {       //���������볣��������11
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