#include <iostream>
using namespace std;
// cos(x) + x Ц 7 от 5 до 6

void main() {
	double e = 0.0001, x, a, b;

	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;

	while (abs(a - b) > 2 * e) {
		x = (a + b) / 2;
		if ((cos(x) + x - 7) * (cos(x) + x - 7) <= 0)
			b = x;
		else
			a = x;
	}

	cout << x;
}