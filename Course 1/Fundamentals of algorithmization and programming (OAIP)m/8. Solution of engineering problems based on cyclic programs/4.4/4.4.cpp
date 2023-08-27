#include <iostream>
using namespace std;
// 9 вариант от 0 до 1

void main() {
	double e = 0.0001, x, a, b;

	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;

	while (abs(a - b) > 2 * e) {
		x = (a + b) / 2;
		if ((pow(x, 3) + 3*x - 1) * (pow(a, 3) + 3*a - 1) <= 0)
			b = x;
		else
			a = x;
	}

	cout << x;
}