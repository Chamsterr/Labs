#include <iostream> 
#include <cmath>
using namespace std; // ��� 1, ������� 6

double f(double x) {
	return 1 + pow(x, 3);
}
double trapeze(double a, double b, int n)
{
	double h = (b - a) / n;
	double sum = f(a) + f(b);
	for (int i = 1; i <= n - 1; i++)
	{
		sum += 2 * f(a + i * h);
	}
	sum *= h / 2;
	return sum;
}
double parabola(double a, double b, int n)
{
	double h = (b - a) / n;
	double sum = f(a) + f(b);
	int k;
	for (int i = 1; i <= n - 1; i++)
	{
		k = 2 + 2 * (i % 2);
		sum += k * f(a + i * h);
	}
	sum *= h / 3;
	return sum;
}


int main()
{
	int i;
	double a = 1, b = 5, n = 200;
	cout << "Trapeze " << trapeze(a, b, n) << endl;
	cout << "Parabola " << parabola(a, b, n) << endl;
	return 0;
}