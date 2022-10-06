#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char c = 'N';
    char* pc = &c;

    char c1 = 'L';
    char* pc1 = &c1;

    ofstream fout;

    fout.open("../Serialization.txt");

    if (fout.is_open()){
       fout << "0x01" << ' ' << "0x" << hex << (int)*pc << std::endl;
       fout << "0x02" << ' ' << "0x" << hex << (int)'P' << std::endl;
       fout << "0x01" << ' ' << "0x" << hex << (int)*pc1 << std::endl;
       fout << "0x02" << ' ' << "0x" << hex << (int)'O' << std::endl;
    }
    return 0;
}