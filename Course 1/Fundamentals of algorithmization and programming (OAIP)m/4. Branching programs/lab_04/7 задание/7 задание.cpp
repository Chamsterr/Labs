#include <iostream>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	int a, b, c, k;
	cout << "������� ������ �����"; cin >> a;
	cout << "������� ������ �����"; cin >> b;
	cout << "������� ������ �����"; cin >> c;

	
	(a % 5 == 0 && b % 5 == 0 && c % 5 == 0) ? k = a + b + c,  cout << "k=" << k : cout << "error";
}