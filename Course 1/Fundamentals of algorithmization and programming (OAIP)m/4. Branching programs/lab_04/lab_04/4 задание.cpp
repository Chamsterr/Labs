#include <iostream>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	int a, b, c;
	cout << "������� a ";
	cin >> a;
	cout << "������� b ";
	cin >> b;
	cout << "������� c ";
	cin >> c;
	if ((a < b) && (b < c))
	{
		a = c, b = c;
		cout << "a=" << a << endl;
		cout << "b=" << b << endl;
		cout << "c=" << c << endl;	
	}

	else if ((a > b) && (b > c))
		{
		cout << "a=" << a << endl;
		cout << "b=" << b << endl;
		cout << "c=" << c << endl;
		}

	else 
	{
		a = pow(a, 2);
		b = pow(b, 2);
		c = pow(c, 2);
		cout << "a=" << a << endl;
		cout << "b=" << b << endl;
		cout << "c=" << c << endl;
	}
}