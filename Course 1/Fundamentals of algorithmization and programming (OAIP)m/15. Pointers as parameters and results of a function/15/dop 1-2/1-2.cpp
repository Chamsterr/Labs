#include <iostream> 
#include <cmath>
using namespace std; // доп 2, вариант 1

double f(double x) {
	return pow(x, 3) + x - 3;
}
double f1(double x) {
	return 3 * pow(x, 2) + 1;
}
double f2(double x) {
	return 6 * x;
}
double dichotomy(double a, double b, double x)
{
	double e = 0.0001;
	while (abs(a - b) > 2 * e)
	{
		x = (a + b) / 2;
		if (f(a) * f(x) <= 0)
			b = x;
		else
			a = x;
	}
	return x;
}
double tangents(double a, double b, double x)
{
	double e = 0.0001;
	if (f(a) * f2(a) > 0)
		x = a;
	else x = b;
	do {
		x -= f(x) / f1(x);
	} while (abs(f(x)) > e);
	return x;
}
int main()
{

	double a = -5, b = 10, x = 1;
	cout << "Dichotomy " << dichotomy(a, b, x) << endl;
	cout << "Tangents " << tangents(a, b, x) << endl;
	return 0;
}