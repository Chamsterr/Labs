#include <iostream>
using namespace std;
//e^x + 2
void main() {

	float s, z, x, s1 = 0.0, s2 = 0.0, i = 1.0, a = 5.0, b = 11.0, n = 200.0, h;

	h = (b - a)/(2*n);
	x = a + 2*h;

	while (i < n) {
		s2 = s2 + (exp(x) + 2);
		x = x + h;
		s1 = s1 + (exp(x) + 2);
		x = x + h;
		i = i + 1;
	}

	z = h / 3 * ((exp(a)+ 2) + 4 * (exp(a + h) + 2)  + 4 * s1 + 2 * s2 + (exp(b) + 2));
	cout << z;
}