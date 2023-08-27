#include <iostream>
using namespace std;
//cos(x)^3 
void main() {

	float s, z, x, s1 = 0.0, s2 = 0.0, i = 1.0, a = 4.0, b = 7.0, n = 200.0, h;

	h = (b - a) / (2 * n);
	x = a + 2 * h;

	while (i < n) {
		s2 = s2 + (pow(x, 3) + 3);
		x = x + h;
		s1 = s1 + (pow(x, 3) + 3);
		x = x + h;
		i = i + 1;
	}

	z = h / 3 * ((pow(a, 3) + 3) + 4 * (pow((a + h), 3) + 3) + 4 * s1 + 2 * s2 + (pow(b, 3) + 3));
	cout << z;
}