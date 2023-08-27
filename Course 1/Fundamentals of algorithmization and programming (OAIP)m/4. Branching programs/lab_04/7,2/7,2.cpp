#include <iostream>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	int a, b, c;
	char d;
	cout << "введите первое число a=";
	cin >> a;
	cout << "введите второе число b=";
	cin >> b;
	cout << "выберете действие (+, -, *, /, %)";
	cin >> d;
	if (d == '+') {
		c = a + b;
		cout << "c=" << c << endl;
	}
	else if (d == '-') {
		c = a - b;
		cout << "c=" << c << endl;
	}

	else if (d == '/') {
		c = a / b;
		cout << "c=" << c << endl;
	}

	else if (d == '*') {
		c = a * b;
		cout << "c=" << c << endl;
	}

	else if (d == '%') {
		c = a % b;
		cout << "c=" << c << endl;
	}
	else {
		cout << "Попробуй еще :("<< endl;
	}
}