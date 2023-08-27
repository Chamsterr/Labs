#include <iostream>
using namespace std;

void main() {
	setlocale(LC_CTYPE, "Russian");
	int a = 4, k = 1;
	float x, y, c = 3.7, d = 51.9e-2;
	x = tan(pow(a, 2) - 1) / (d + 1);
	while (c < 5)
	{
		if (3 * x < a * c)
		{
			y = a * k + d;
			cout << y << endl;
			c = c + 0.1;
		}
		else
		{
			y = cos(a * k) * exp(a + 1);
			cout << y << endl;
			c = c + 0.1;
		}
	}
}
