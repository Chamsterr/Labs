#include <iostream>
//x^3 - 3 1 �������
using namespace std;

void main() {

	float s, z, x, h, a = 1.0, b = 3.0, n = 200.0;

	h = (b - a) / n;
	x = a;
	s = 0;

	while (x <= b - h) {
		s = s + (h * (pow(x, 3) - 3) + (pow((x + h), 3) - 3)) / 2;
		x = x + h;
	}
	cout << s;
}