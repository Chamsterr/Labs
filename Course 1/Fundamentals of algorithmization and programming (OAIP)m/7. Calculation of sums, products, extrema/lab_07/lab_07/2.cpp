/*

#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	float a, sum = 0; int i;
	const int size = 4;
	for (i = 1; i <= size; i++)
	{
		cout << "Введите a" << i << endl;
		cin >> a;
		sum = sum + a;
	}
	cout << "Ответ " << sum << endl;
}

#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_CTYPE, "Russian");
	float a, fac = 1; int i, n;
	cout << "Введите факториал x!=";
	cin >> i;
	for (n = 1; n <= i; n++)
	{
		fac = fac * n;
	}
	cout << "Ответ " << fac << endl;
}
*/

#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_CTYPE, "Russian");
	float c, a, b, sum = 0;
	int i;
	const int size = 6;
	for (i = 1; i <= size; i++)
	{
		cout << "Введите a" << i << "=";
		cin >> a;
		cout << "Введите b" << i << "=";
		cin >> b;
		c = sqrt(a + b);
		for (int n = 1; n <= 6; n++)
			sum = sum + (c / i);
		cout << "sum=" << sum << endl;
	}
}
