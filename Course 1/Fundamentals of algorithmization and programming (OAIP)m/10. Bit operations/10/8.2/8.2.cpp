#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	char tmp[33];
	int A, B, n, m, maskA = 7;
	int maskB = ~maskA;
	cout << "Первое число="; cin >> A;
	cout << "n="; cin >> n;
	cout << "Второе число="; cin >> B;
	cout << "m="; cin >> m;

	_itoa_s(A, tmp, 2); cout << "A=" << tmp << endl;
	_itoa_s(B, tmp, 2); cout << "B=" << tmp << endl;

	_itoa_s(maskA << n, tmp, 2);
	cout << "Маска для А: " << tmp << endl;

	_itoa_s(B & (maskB >> m) | (A & maskA >> n), tmp, 2);
	cout << " Результат B=" << tmp << endl;
}