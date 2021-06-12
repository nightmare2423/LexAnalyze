#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Lexdyd {//二元式，单词符号和序号
public:
	string type;  //单词符号
	int num;   //种别编号
	int l;   //所在行数

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
		return dyd;   //是否得到标准的二元式结构
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

