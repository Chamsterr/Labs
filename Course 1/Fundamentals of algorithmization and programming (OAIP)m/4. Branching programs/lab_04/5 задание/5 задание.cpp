#include <iostream>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	float a, b;
	cout << "введите год" << endl;
	cin >> a;
	b = a / 4;
	if (b == int(b))
	{
		cout << "год високосный" << endl;
	}
	else
	{
		cout << "год не високосный" << endl;
	}
}