#include <iostream>
using namespace std;
void main() {
	setlocale(LC_CTYPE, "Russian");
	char tmp[33];
	int A, B, C, n, p, t, m, q;

	cout << "Вариант 12\n\n";
	cout << "Задание №2" << endl;

	cout << "Первое число A="; cin >> A;
	C = A;

	_itoa_s(A, tmp, 2); cout << tmp << endl;

	cout << "Второе число B="; cin >> B;

	_itoa_s(B, tmp, 2); cout << tmp << endl;

	/*Запись 0*/
	cout << "Введите с какого бита вырезаем "; cin >> n;
	t = n;
	n = n - 1;
	cout << "Введите сколько бит меняем "; cin >> p;
	cout << "Результат" << endl;

	for (int i = 1; i <= p; i++) {

		C = C & (~(1 << n));

		_itoa_s(C, tmp, 2);

		n += 1;

		if (i == p) {

			cout << tmp << endl;

		}
	}

	/*Заданеи 2*/

	int maskA = A;
	int maskB = ~maskA >> 1;

	cout << "Второе задание" << endl;
	cout << "С какого бита меняем" << endl; cin >> m;



	_itoa_s( ((B & (maskB << m) ) | (A  & maskA << m) ), tmp, 2);
														
	cout << " Результат B=" << tmp << endl;
}

/*
&      |      ^      ~ 
x y z  x y z  x y z  инвертирует 
0 1 0  1 0 1  0 0 0  число
1 0 0  0 1 1  0 1 1
1 1 1  0 0 0  1 0 1
0 0 0  1 1 1  1 1 0
*/