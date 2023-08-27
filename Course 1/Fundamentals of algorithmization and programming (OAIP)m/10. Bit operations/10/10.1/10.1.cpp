#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	char tmp[33];
	int A, B, maskA = 126;
	int maskB = ~maskA >> 1;
	cout << "Первое число="; cin >> A;


	_itoa_s(A, tmp, 2); cout << "A=" << tmp << endl;

	_itoa_s(maskA, tmp, 2);
	cout << "Маска для А: " << tmp << endl;

	_itoa_s((A & maskA) >> 1, tmp, 2);
	cout << "Выделенные биты А: "  << tmp << endl;
}