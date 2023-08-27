//Установить в 1 в числе А n битов влево от позиции p, заменить ими m битов числа В, начиная с позиции q.

#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	char tmp[33];
	int A, B, p, n, q, g, mask = 0, maskA, maskB;

	cout << "Первое число A="; cin >> A;
	cout << "C какого бита начинаем? p="; cin >> p;
	cout << "Сколько битов убираем? n="; cin >> n;
	cout << "Второе число B="; cin >> B;
	cout << "С какого бита начинаем? q="; cin >> q;

	for (int i = 0; i < n; i++)
		mask = mask + pow(2, i);

	maskA = mask << (p - 1);
	maskB = ~(mask << (q - 1));

	_itoa_s(A, tmp, 2); cout << "A=" << tmp << endl;
	_itoa_s(B, tmp, 2); cout << "B=" << tmp << endl;

	_itoa_s(maskA, tmp, 2);
	cout << "Маска для А: " << tmp << endl;

	_itoa_s((A & maskA) >> (p - 1), tmp, 2);
	cout << "Выделенные биты А: " << tmp << endl;

	_itoa_s(maskB, tmp, 2);
	cout << "Маска для В: " << tmp << endl;

	_itoa_s(B & maskB, tmp, 2);
	cout << " Очищены биты в B: " << tmp << endl;

	_itoa_s(A | maskA, tmp, 2);
	cout << "Новые биты в A: " << tmp << endl;

	g = q - p;
	_itoa_s(((B & maskB) | ((A & maskA)) <<  g), tmp, 2);
	cout << " Результат B=" << tmp << endl;
}