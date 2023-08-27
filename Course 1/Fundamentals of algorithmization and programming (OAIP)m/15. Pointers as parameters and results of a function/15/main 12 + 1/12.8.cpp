#include <stdio.h>
#include <string>
#include <iostream>>
using namespace std;

void manin(){
	setlocale(LC_ALL, "Russian");
	int n1 = 1000, n2= 1000;
	char str1, str2;

	char* arr = new char[n1];
	char* arr2 = new char[n2];

	cout << "Введите первое предложение:";
	cin >> arr;

	cout << "Введите второе предложение:";
	cin >> arr2;

	delete[] arr;
	delete[] arr2;

}