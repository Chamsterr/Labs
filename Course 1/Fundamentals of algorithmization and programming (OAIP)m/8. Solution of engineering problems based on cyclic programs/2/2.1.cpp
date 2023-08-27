#include <iostream>
//cos(x)^3 2 вариант
using namespace std;

void main() {

	float s, z, x, h, a = 4.0, b = 7.0, n = 200.0;

	h = (b - a) / n;
	x = a;
	s = 0;

	while (x <= b - h) {
		s = s + (h * (pow(cos(x), 3) + pow(cos(x + h), 3)) / 2);
		x = x + h;
	}
	cout << s;
}