#include <iostream>
using namespace std;

void main() {
	setlocale(LC_CTYPE, "Russian");
	int num, counter, sum = 0, del= 1;
	for (int counter = 1; true; counter++) {
		cout << "������� n= (��� ��������� �������� '00')" ;
		cin >> num;
		if (num > 0) {
			if (num % 2 != 0) {
				sum = (sum + num)/del;
				del = del + 1;
			}
		}
		if (num == 00) {
				break;
		}

		if (num < 0) {
			cout << "��� �� ����������� �����";
		}	
	}
	cout << "������� �������������� ����������� �������� ����� sum=" << sum;
}