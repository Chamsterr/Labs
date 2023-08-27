#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	char tmp[33];
	int A, p, n, g, mask = 0, maskA;

	cout << "Первое число A="; cin >> A;
	cout << "C какого бита начинаем? p="; cin >> p;
	cout << "Сколько битов убираем? n="; cin >> n;

	for (int i = 0; i < n; i++)
		mask = mask + pow(2, i);

	maskA = mask << p - 1;

	_itoa_s(A, tmp, 2); cout << "A=" << tmp << endl;

	_itoa_s(maskA, tmp, 2);
	cout << "Маска для А: " << tmp << endl;


	_itoa_s(A | maskA, tmp, 2);
	cout << "Новые биты в A: " << tmp << endl;
}