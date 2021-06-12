#pragma once
#include "basic.h"

string NAME = "Lex";

string readpas() {
    string ans_string;
    ifstream file(NAME+".pas");
    while (!file.eof()) {
        string tempstr;
        getline(file, tempstr);
        tempstr += "\n";
        ans_string += tempstr;
    }
    return ans_string;
}

bool writedyd(vector<Lexdyd*> dyd) {
    ofstream file(NAME+".dyd");
    for (int i = 0; i < dyd.size(); i++) {
        file << dyd[i]->makedyd() << endl;
    }
    return true;
}

int writeerr(vector<Lexdyd*> dyd) {
    ofstream file(NAME + ".err");
    int count = 0;
    for (int i = 0; i < dyd.size(); i++) {
        string temp = dyd[i]->makeerr();
        if (temp != " ") {
            file << temp << endl;
            count++;
        }
    }
    if(count)file << count << " error(s) in this file!";
    return count;
}
