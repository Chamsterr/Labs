#include <iostream> 
#include <cmath>
using namespace std; // доп 2, вариант 5

double f(double x) {
	return 2 - pow(x, 2) + x;
}
double f1(double x) {
	return -2 * x + 1;
}
double f2(double x) {
	return -2;
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

	double a = -4, b = -1, x = 1;
	cout << "Dichotomy " << dichotomy(a, b, x) << endl;
	cout << "Tangents " << tangents(a, b, x) << endl;
	return 0;
}