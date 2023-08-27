#include <iostream>
using namespace std;

void main() {
	double e = 0.0001, x = 0, x1 = 0, a, b;

	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;

	while (abs(x1 - x) <= e) {
		if ((exp(x) + x - 4) * exp(x) > 0)
			x1 = a;
		else
			x1 = b;

		x = x1;
		x1 = x - ((exp(x) + x - 4) / (exp(x)+1));
	}
	cout << x1;
}