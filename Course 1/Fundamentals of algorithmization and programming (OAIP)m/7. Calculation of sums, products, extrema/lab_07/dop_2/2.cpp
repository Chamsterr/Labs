#include <iostream>
using namespace std;

void main() {
	setlocale(LC_CTYPE, "Russian");
	int num, counter;

	for (int counter = 1; true; counter++){
		cout << "Введите число num=";
		cin >> num;
		if (num < 0) {
			cout << "Первое отрицательное число: " << num << " " << "Порядковый номер:" << counter;
			break;
		}
	}
}