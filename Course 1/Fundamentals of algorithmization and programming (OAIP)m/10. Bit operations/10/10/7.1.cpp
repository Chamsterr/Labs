#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	char tmp[33];
	int A, B, maskA = 240;
	int maskB = ~maskA >> 4;
	cout << "������ �����="; cin >> A;
	cout << "������ �����="; cin >> B;

	_itoa_s(A, tmp, 2); cout << "A=" << tmp << endl;
	_itoa_s(B, tmp, 2); cout << "B=" << tmp << endl;

	_itoa_s(maskA, tmp, 2);
	cout << "����� ��� �: " << tmp << endl;

	_itoa_s((A & maskA) >> 4, tmp, 2);
	cout << "���������� ���� �: " << tmp << endl;

	_itoa_s(maskB, tmp, 2);
	cout << "����� ��� �: " << tmp << endl;

	_itoa_s(B & maskB, tmp, 2);
	cout << " ������� ���� � B: " << tmp << endl;

	_itoa_s(((B & maskB) | ((A & maskA) >> 4)), tmp, 2);
	cout << " ��������� B=" << tmp << endl;
}