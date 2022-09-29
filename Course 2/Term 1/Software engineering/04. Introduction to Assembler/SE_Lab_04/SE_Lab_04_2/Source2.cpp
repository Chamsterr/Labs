#include <iostream>
#include <typeinfo>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string word;
    ifstream fin;
    ofstream fout;

    fin.open("../Serialization.txt");
    fout.open("../SE_Lab_04_3/Source.asm");

    fout << ".586P \n.MODEL FLAT, STDCALL \nincludelib kernel32.lib \nExitProcess PROTO : DWORD \n.STACK 586 \n.DATA \n";

    while (fin >> word){
        cout << word << endl;
        if (word == "0x01") {
            fin >> word;
            char letter = stoi(word, 0, 16);
            fout << "   char_ BYTE \"" << letter << "\", 0\n";
        }
        else if (word == "0x02") {
            fin >> word;
            char letter = stoi(word, 0, 16);
            fout << "   literal BYTE \"" << letter << "\", 0\n";
        }
    }

    fout << ".CODE \nmain PROC \nSTART: \n    invoke ExitProcess, 0\n    \nmain ENDP \nend main";

    return 0;
}