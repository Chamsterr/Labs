#include <iostream>
using namespace std;
//e^x + 2

void main() {

	float s, z, x, h, a = 5.0, b = 11.0, n = 200.0;

	h = (b - a) / n;
	x = a;
	s = 0;

	while (x <= b - h) {
		s = s + h * ((exp(x) + 2) + ((exp(x + h) + 2)) / 2);
		x = x + h;
	}
	cout << s;
}