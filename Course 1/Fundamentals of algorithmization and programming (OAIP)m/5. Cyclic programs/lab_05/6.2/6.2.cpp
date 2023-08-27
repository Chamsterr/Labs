#include <iostream>
#include <iomanip>
using namespace std;

void main() {
	setlocale(LC_CTYPE, "Russian");
	double P1, Q, n, P=0, d;
	cout << "Сколько реализуется товара в день P=";
	cin >> P1;
	d = P1;
	P = P1;
	cout << "Необходимая выручка Q=";
	cin >> Q;
		for (n = 2; P<Q; n++)
		{
			d = d * 1.03;
			P = P + d;
			cout << "Выручка на " << n << ": " << P << endl;
		}
		cout << "На " << n -1  << " день выручка привысит необходимую выручку и составит: " << P << "руб";
}