#include <iostream>
#include <iomanip> 
using namespace std;
void main()

{
	setlocale(LC_CTYPE, "Russian");
	char probel; probel = ' ';
	double x, y = 2, i = 1, z, q, n, t = 1;
	while (t <= 3) {
		for (int n = 1; n <= 3; n++) {
			cout << "¬ведите x=";
			cin >> x;
			z = t * pow(y, 2) - sqrt(i + x) * tan(y);
			q = sqrt(pow(z, 2) + 5 * z) * log(y);
			cout << "z=" << z << probel;
			cout << "q=" << q << endl;
			t = t + 1;

		}
	}
}

	