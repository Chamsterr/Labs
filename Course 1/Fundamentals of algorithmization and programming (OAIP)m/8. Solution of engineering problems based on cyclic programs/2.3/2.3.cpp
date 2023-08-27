#include <iostream>
using namespace std;
// cos(x) + x – 7

void main() {
	double e = 0.0001, x = 0, x1 = 0, a, b;

	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;

	while (abs(x1 - x) <= e) {
		if ((cos(x) + x - 7) * (-cos(x)) > 0)
			x1 = a;
		else
			x1 = b;

		x = x1;
		x1 = x - ((cos(x) + x - 7) / (-sin(x) + 1));
	}
	cout << x1;
}