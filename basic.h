#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Lexdyd {//��Ԫʽ�����ʷ��ź����
public:
	string type;  //���ʷ���
	int num;   //�ֱ���
	int l;   //��������

	Lexdyd() {}
	Lexdyd(string _type, int _num, int _l) {
		this->type = _type;
		this->num = _num;
		this->l = _l;
	}

	virtual string makedyd() {
		string dyd = type;
		while (dyd.length() < 16) {
			dyd = " " + dyd;
		}
		dyd += " ";
		if (num < 10) {
			dyd += '0';
		}
		dyd += to_string(num);
		return dyd;   //�Ƿ�õ���׼�Ķ�Ԫʽ�ṹ
	};

	virtual string makeerr() {
		return " ";
	};
};


class Lexerr :public Lexdyd {
public:
	Lexerr() {};
	Lexerr(string _type, int _num, int _l) {
		this->type = _type;
		this->num = _num;
		this->l = _l;
	};

	string makedyd() {
		return "*******************";
	};
	string makeerr() {
		string err = "***LINE:" + to_string(l) + "  ";
		string errtype;
		switch (num) {
		case -1:errtype = "illegal identifier";
			break;
		case -2:errtype = "colon mismatch";
			break;
		case -3:errtype = "identifier overflow";
			break;
		case -4:errtype = "out of integer range";
			break;
		}
		return err + errtype+"  \" "+type+" \"";
	};

};

string dic[9] = { "begin", "end","integer",
					"if","then","else",
					"function","read","write" };

