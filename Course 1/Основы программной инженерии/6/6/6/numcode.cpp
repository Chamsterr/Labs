#include "numcode.h"

void numcode(){
	using namespace std;
	setlocale(LC_ALL, "Russian");
	int code_num;
	char num;

	cout << "������� � ���������� �����" << endl;
	cin >> num;

	code_num = char(num);
	cout << "�� ����� ����� � ����� " << code_num << endl;
}
