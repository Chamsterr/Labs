#include <iostream>
using namespace std;
// x^3 + 3x – 1

void main() {
	double e = 0.0001, x = 0, x1 = 0, a, b;

	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;

	while (abs(x1 - x) <= e) {
		if ((pow(x, 3) + 3*x - 1) * (6 * (x)) > 0)
			x1 = a;
		else
			x1 = b;

		x = x1;
		x1 = x - ((pow(x, 3) + 3*x - 1) / (3 * pow(x, 2) + 3));
	}
	cout << x1;
}