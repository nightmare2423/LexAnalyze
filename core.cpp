#include "Lex.h"
#include "files.h"


Lexdyd* make_word();

int l = 1;

int main() {
    make_table();
    vector<Lexdyd*> myans;
    string test = readpas();     //将文件以字符串形式读入
    place = &test[0];
    int n = test.size();
    Lexdyd* temp;
    char* place_end = &test[n - 1];
    while (place <= place_end) {//循环读入
        temp = make_word();
        myans.push_back(temp);
    }
    temp = new Lexdyd("EOF", 25, l);   //补一个EOF
    myans.push_back(temp);     //最终结果

    writedyd(myans);   //将结果写入到文件中
    writeerr(myans);   //将报错写入到文件中

    return 0;
}


Lexdyd* make_word() {
    string type;
    int num;
    token = "";
    Getchar();
    Getnbc();
    if (Isletter()) {
        while (Isletter() || Isdigit()) {
            concat();
            Getchar();
        }
        retract();
        type = token;
        num = reserve();  // 标识符或保留字
    }
    else if (Isdigit()) {
        while (Isdigit()) {
            concat();
            Getchar();
        }
        retract();
        type = token;
        num = constant();  // 常数
    }
    else if (c_new == '=') {
        Getchar();
        if (c_new == '=') {
            num = 13; // ==
            type = "==";
        }
        else {
            retract();
            num = 12; // =
            type = "=";
        }
    }
    else if (c_new == '-') {
        type = "-";
        num = 18;
    }
    else if (c_new == '*') {
        type = "*";
        num = 19;
    }
    else if (c_new == '(') {
        type = "(";
        num = 21;
    }
    else if (c_new == ')') {
        type = ")";
        num = 22;
    }
    else if (c_new == '<') {
        Getchar();
        if (c_new == '=') {
            type = "<=";
            num = 14; // <=
        }
        else {
            retract();
            type = "<";
            num = 15; // <
        }
    }
    else if (c_new == '>') {
        Getchar();
        if (c_new == '=') {
            type = ">=";
            num = 16; // >=
        }
        else {
            retract();
            type = ">";
            num = 17;  // >
        }
    }
    else if (c_new == ':') {
        Getchar();
        if (c_new == '=') {
            type = ":=";
            num = 20; // :=
        }
        else {
            retract();
            type = ":";
            num = -2;//第二种错误
        }
    }
    else if (c_new == ';') {
        type = ";";
        num = 23;  // ;
    }
    else if (c_new == '\n') {
        l++;
        type = "EOLN";
        num = 24;
    }
    else {
        type = c_new;
        num = -1;//第一种错误
    }
    Lexdyd* temp;
    if (type.length() > 16 && num>0)num = -3;//第三种错误
    if (num < 0) {
        temp = new Lexerr(type, num, l);
    }
    else temp = new Lexdyd(type, num, l);
    return temp;
}
