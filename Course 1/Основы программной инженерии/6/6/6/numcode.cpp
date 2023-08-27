#include "numcode.h"

void numcode(){
	using namespace std;
	setlocale(LC_ALL, "Russian");
	int code_num;
	char num;

	cout << "Введите с клавиатуры цифру" << endl;
	cin >> num;

	code_num = char(num);
	cout << "Вы ввели цифру с кодом " << code_num << endl;
}
