#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std;

void compr(char* str) {
	int k = strlen(str);
	for (int i = 0; i < k; i++)
	{
		if (str[i] == ' ')
		{
			for (int j = i; j < k + 1; j++)
			{
				str[j] = str[j + 1];
			}
			k--;
		}
	}
	cout << str << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
	char str[100];
	gets_s(str);
	compr(str);
}