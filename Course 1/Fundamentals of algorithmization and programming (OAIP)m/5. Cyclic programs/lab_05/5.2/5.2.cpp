#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	char probel; probel = ' ';
	double x = 0.9, y = 2, t = 6.96 * pow(10, -5), i = 1, z, q;
	while (i <= 2) {

		z = t * pow(y, 2) - sqrt(i + x) * tan(y);
		q = sqrt(pow(z, 2) + 5 * z) * log(y);
		cout << "z=" << z << probel;
		cout << "q=" << q << endl;
		i = i + 0.2;
	}
	return 0;
}