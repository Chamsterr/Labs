#include <iostream>
#include <fstream>
#include <string>
#include "Header2.h"
#include <list>
#include <map>

using namespace std;

list<string> chars;
list<string> consts;

map<string, string> types_map = {
    { "0x01", "char"},
    { "0x02", "literal"}
};

string printData(ofstream& fout, string type){
    string text = "";
    if (type == "0x02"){
        int size = consts.size();
        for (int i = 0; i < size; i++) {
            string var = VARCONSTRUCTOR(stoi(consts.front(), 0, 16));
            consts.pop_front();
            text = text + var;
        }
    }

    if (type == "0x01") {
        int size = chars.size();
        for (int i = 0; i < size; i++) {
            string var = VARCONSTRUCTOR(stoi(chars.front(), 0, 16));
            chars.pop_front();
            text = text + var;
        }
    }

    return text;
}


int main()
{
    string word;
    ifstream fin;
    ofstream fout;

    fin.open("../Serialization.txt");
    fout.open("../SE_Lab_04_3/Source.asm");


    while (fin >> word) {
        if (word =="0x02"){
            fin >> word;
            chars.push_front(word);
        }
        else if (word == "0x01") {
            fin >> word;
            consts.push_front(word);
        }
    }

    fout << COMMAND_SYSTEM(".", 586) << MODEL("FLAT"s, "STDCALL"s) << INCLUDELIB("kernel32.lib"s) << "ExitProcess PROTO : DWORD \n" << STACK(1024) << CONST(fout, "0x02") << DATA(fout, "0x01") << CODE << INVOKE("ExitProcess"s) << ENDCODE;

    return 0;
}