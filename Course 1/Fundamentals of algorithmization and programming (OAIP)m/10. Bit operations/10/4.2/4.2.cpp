#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	char tmp[33];
	int A, p, n, g, mask = 0, maskA;

	cout << "������ ����� A="; cin >> A;
	cout << "C ������ ���� ��������? p="; cin >> p;
	cout << "������� ����� �������? n="; cin >> n;

	for (int i = 0; i < n; i++)
		mask = mask + pow(2, i);

	maskA = mask << p - 1;

	_itoa_s(A, tmp, 2); cout << "A=" << tmp << endl;

	_itoa_s(maskA, tmp, 2);
	cout << "����� ��� �: " << tmp << endl;


	_itoa_s(A | maskA, tmp, 2);
	cout << "����� ���� � A: " << tmp << endl;
}