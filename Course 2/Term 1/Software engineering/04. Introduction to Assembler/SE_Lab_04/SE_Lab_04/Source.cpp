#include <iostream>
#include <typeinfo>
#include <fstream>
using namespace std;

int main()
{
    char test;
    char c = 'N';
    char* pc = &c;

    ofstream fout;

    fout.open("../Serialization.txt");

    if (fout.is_open()){
       fout << "0x01" << ' ' << "0x" << hex << (int)*pc << std::endl;
       fout << "0x02" << ' ' << "0x" << hex << (int)'P' << std::endl;
    }


    return 0;
}