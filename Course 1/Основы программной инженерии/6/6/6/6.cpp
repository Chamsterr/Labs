#include<iostream>
#include <cctype>
#include "difLat.h"
#include "difRu.h"
#include "numcode.h"

void main(){
	using namespace std;
	setlocale(LC_ALL, "Russian");
	char title_letter, lower_letter, code_title_letter, code_lower_letter;
	int variant, difference;
	bool run = true;

	while(run) {

		cout << "\nВыберите, что необходимо сделать с вашим элементом:" << endl;
		cout << "1.Определение разницы значений кодов в Windows-1251 буквы латинского алфавита в прописном и строчном написании; " << endl;
		cout << "2.Определение разницы значений кодов в Windows-1251 буквы русского алфавита в прописном и строчном написании; " << endl;
		cout << "3.Вывод в консоль кода символа, соответствующего введенной цифре;" << endl;
		cout << "4.Выход из программы." << endl;

		cin >> variant;

		switch (variant)
		{
		case 1:
			difLat();
			continue;

		case 2:
			difRu();
			continue;

		case 3:
			numcode();
			continue;

		case 4:
			run = false;
			break;

		default:
			cout << "Введите корректный вариант" << endl;
			break;
		}
	}
}