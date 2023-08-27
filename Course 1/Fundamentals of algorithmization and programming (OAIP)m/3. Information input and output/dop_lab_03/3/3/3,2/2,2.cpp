#include <iostream>
#include <iomanip>

void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	float a, b, c, m;
	cout << "¬ведите m=";
	cin >> m;
	c = m - 5;
	b = c / 2;
	a = 5 + b;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
}
