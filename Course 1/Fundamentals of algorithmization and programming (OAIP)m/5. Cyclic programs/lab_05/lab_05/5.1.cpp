#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	char probel; probel = ' ';
	double x = 0.9, y = 2, t = 6.96 * pow(10, -5), i, z, q;
	for (int n = 1; n <= 3; n++) {
		cout << "¬ведите i=";
		cin >> i;
		z = t * pow(y, 2) - sqrt(i + x)* tan(y);
		q = sqrt(pow(z, 2) + 5* z) * log(y);
		cout << "z=" << z << probel;
		cout << "q=" << q << endl; 
	}
	return 0;
}