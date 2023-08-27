#include <iostream> 
#include <cmath>
using namespace std;

double f(double x) {
	return pow(x, 3) + x - 2;
}

double f2(double x) {
	return sin(x) + 0.3;
}

double (*foo)(double x);

double dichotomy(double foo(double x), double x, double a, double b)
{
	double e = 0.0001;
	while (abs(a - b) > 2 * e)
	{
		x = (a + b) / 2;
		if (foo(a) * foo(x) <= 0)
			b = x;
		else
			a = x;
	}
	return x;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	double x, a, b;

	cout << "¬ведите x" << endl;
	cin >> x;

	cout << "¬ведите a" << endl;
	cin >> a;

	cout << "¬ведите b" << endl;
	cin >> b;

	cout << dichotomy(f, x, a, b) << endl;
	cout << dichotomy(f2, x, a, b);
}
