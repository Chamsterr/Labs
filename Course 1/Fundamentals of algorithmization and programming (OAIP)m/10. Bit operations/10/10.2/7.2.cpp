//���������� � 1 � ����� � n ����� ����� �� ������� p, �������� ��� m ����� ����� �, ������� � ������� q.

#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	char tmp[33];
	int A, B, p, n, q, g, mask = 0, maskA, maskB;

	cout << "������ ����� A="; cin >> A;
	cout << "C ������ ���� ��������? p="; cin >> p;
	cout << "������� ����� �������? n="; cin >> n;
	cout << "������ ����� B="; cin >> B;
	cout << "� ������ ���� ��������? q="; cin >> q;

	for (int i = 0; i < n; i++)
		mask = mask + pow(2, i);

	maskA = mask << (p - 1);
	maskB = ~(mask << (q - 1));

	_itoa_s(A, tmp, 2); cout << "A=" << tmp << endl;
	_itoa_s(B, tmp, 2); cout << "B=" << tmp << endl;

	_itoa_s(maskA, tmp, 2);
	cout << "����� ��� �: " << tmp << endl;

	_itoa_s((A & maskA) >> (p - 1), tmp, 2);
	cout << "���������� ���� �: " << tmp << endl;

	_itoa_s(maskB, tmp, 2);
	cout << "����� ��� �: " << tmp << endl;

	_itoa_s(B & maskB, tmp, 2);
	cout << " ������� ���� � B: " << tmp << endl;

	_itoa_s(A | maskA, tmp, 2);
	cout << "����� ���� � A: " << tmp << endl;

	g = q - p;
	_itoa_s(((B & maskB) | ((A & maskA)) <<  g), tmp, 2);
	cout << " ��������� B=" << tmp << endl;
}