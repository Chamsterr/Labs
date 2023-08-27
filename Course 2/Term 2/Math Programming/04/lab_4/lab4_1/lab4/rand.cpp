#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <ctime> 
using namespace std;

string RandomString(int len)
{
	srand(time(0));
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	string newstr;
	int pos;
	while (newstr.size() != len) {
		pos = ((rand() % (str.size() - 1)));
		newstr += str.substr(pos, 1);
	}
	return newstr;
}

int main()
{
	cout << "String 300" << endl;
	string random_str = RandomString(300);
	cout << random_str << endl;
	cout << "String 200" << endl;
	random_str = RandomString(200);
	cout << random_str << endl;
	system("pause");
}