#include <iostream>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	int a, b, c;
	char d;
	cout << "������� ������ ����� a=";
	cin >> a;
	cout << "������� ������ ����� b=";
	cin >> b;
	cout << "�������� �������� (+, -, *, /, %)";
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
		cout << "�������� ��� :("<< endl;
	}
}