#include <iostream>
#include <iomanip> 
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int a = 1 , a1, a3, a4, a5, a2, a6 = 1, ad;

	//a = a1 * pow(10, 5) + a2 * pow(10, 4) + a3 * pow(10, 3) + a4 * pow(10, 2) + a5 * pow(10, 1) + a6;

	while (a < 1000000) {
		a1 = a / pow(10, 5);
		a2 = a / pow(10, 4) - int(a1) * 10;
		a3 = a / pow(10, 3) - int(a1 * 100) - int(a2 * 10);
		a4 = a / pow(10, 2) - int(a1 * 1000) - int(a2 * 100) - int(a3 * 10);
		a5 = a / pow(10, 1) - int(a1 * 10000) - int(a2 * 1000) - int(a3 * 100) - int(a4 * 10);
		a6 = a - (int(a1 * 100000) + int(a2 * 10000) + int(a3 * 1000) + int(a4 * 100) + int(a5 * 10));
		//a = a1 * pow(10, 5) + a2 * pow(10, 4) + a3 * pow(10, 3) + a4 * pow(10, 2) + a5 * pow(10, 1) + a6;
		if ( float((a1 + a2 + a3 + a4 + a5 + a6) % 7) == 0) {

			ad = a + 1;
			a1 = ad / pow(10, 5);
			a2 = ad / pow(10, 4) - int(a1) * 10;
			a3 = ad / pow(10, 3) - int(a1 * 100) - int(a2 * 10);
			a4 = ad / pow(10, 2) - int(a1 * 1000) - int(a2 * 100) - int(a3 * 10);
			a5 = ad / pow(10, 1) - int(a1 * 10000) - int(a2 * 1000) - int(a3 * 100) - int(a4 * 10);
			a6 = ad - (int(a1 * 100000) + int(a2 * 10000) + int(a3 * 1000) + int(a4 * 100) + int(a5 * 10));
			if (float((a1 + a2 + a3 + a4 + a5 + a6) % 7) == 0) {
				cout << "Номера билетов:" << endl;
				cout << "a=" << a << endl;
				cout << "ad=" << ad << endl;

			}
		}
		a = a + 1;
	}
}