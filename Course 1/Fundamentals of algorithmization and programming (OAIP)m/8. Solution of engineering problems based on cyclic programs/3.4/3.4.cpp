#include <iostream>
using namespace std;
// 1 вариант от 0 до 2

void main() {
	double e = 0.0001, x, a, b;

	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;

	while (abs(a - b) > 2 * e) {
		x = (a + b) / 2;
		if ((pow(x, 3) + x - 3) * (pow(a, 3) + a - 3) <= 0)
			b = x;
		else
			a = x;
	}

	cout << x;
}