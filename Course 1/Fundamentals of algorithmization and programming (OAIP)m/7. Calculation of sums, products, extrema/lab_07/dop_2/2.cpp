#include <iostream>
using namespace std;

void main() {
	setlocale(LC_CTYPE, "Russian");
	int num, counter;

	for (int counter = 1; true; counter++){
		cout << "������� ����� num=";
		cin >> num;
		if (num < 0) {
			cout << "������ ������������� �����: " << num << " " << "���������� �����:" << counter;
			break;
		}
	}
}