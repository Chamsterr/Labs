#include <iostream> 
#include <string> 
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void main()
{
	setlocale(LC_CTYPE, "Russian");
	int a = 100000, a1, a3, a4, a5, a2, a6 = 1, ad, s = 1;
	string p;
	char p1, p2, p3, p4, p5, p6;

	//a = a1 * pow(10, 5) + a2 * pow(10, 4) + a3 * pow(10, 3) + a4 * pow(10, 2) + a5 * pow(10, 1) + a6;

	while (a < 1000000) {
		p = to_string(a);
		p1 = p[0];
		p2 = p[1];
		p3 = p[2];
		p4 = p[3];
		p5 = p[4];
		p6 = p[5];

		a1 = atoi(to_string(p1));
		cout << a1;

		if (float((int(p1) + int(p2) + int(p3) + int(p4) + int(p5) + int(p6)) % 7) == 0) {
				ad = a + 1;
				p = to_string(ad);
				p1 = p[1];
				p2 = p[2];
				p3 = p[3];
				p4 = p[4];
				p5 = p[5];
				p6 = p[6];

				a1 = int(p1);
			
			if (float((int(p1) + int(p2) + int(p3) + int(p4) + int(p5) + int(p6)) % 7) == 0) {
				cout << "Номера билетов:" << endl;
				cout << "a=" << a << endl;
				cout << "ad=" << ad << endl;
			}
		}
		a = a + 1;
	}
}