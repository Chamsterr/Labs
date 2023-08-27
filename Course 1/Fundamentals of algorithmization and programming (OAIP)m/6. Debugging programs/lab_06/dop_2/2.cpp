/*
#include <iostream>
using namespace std;

void main() {
	float k50 = 0.50, k20 = 0.20, k10 = 0.10, k05 = 0.05, k02 = 0.02;
	int r = 1, n50, n20, n10, n05, n02, s=0;

	n50 = r / k50;
	n20 = r / k20;
	n10 = r / k10;
	n05 = r / k05;
	n02 = r / k02;
	
	if (r = r * int(n50 * k50)) {
		s = s + 1;
		cout << r << "=" << n50 << "*" << k50 << endl;
	}

	if (r = r * int(n20 * k20)) {
		s = s + 1;
		cout << r << "=" << n20 << "*" << k20 << endl;
	}

	if (r = r * int(n10 * k10)) {
		s = s + 1;
		cout << r << "=" << n10 << "*" << k10 << endl;
	}

	if (r = r * int(n05 * k05)) {
		s = s + 1;
		cout << r << "=" << n05 << "*" << k05 << endl;
	}

	if (r = r * int(n02 * k02)) {
		s = s + 1;
		cout << r << "=" << n02 << "*" << k02 << endl;
	}

	while (r != 0)


	cout << "s";
}
*/

#include <iostream>
using namespace std;

void main() {
	setlocale(LC_CTYPE, "Russian");
	float C1, C2;
	cout << "Сколько литров в первом сосуде C1=";
	cin >> C1;
	cout << "Сколько литров во втором сосуде C2=";
	cin >> C2;

	for (int f = 1; f < 13; f++) {
		C1 = C1 / 2;
		C2 = C2 + C1;
		C2 = C2 / 2;
		C1 = C1 + C2;
	}

	cout << C1 << endl;
	cout << C2;

 }



