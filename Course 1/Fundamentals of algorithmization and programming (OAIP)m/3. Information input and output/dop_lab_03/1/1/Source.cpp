#include <iostream>
#include <iomanip>

void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	char c, probel; probel = ' ';
	cout << "Введите символ "; cin >> c;
	cout << setw(33) << setfill(probel) << probel;
	cout << setw(7) << setfill(c) << c << endl;
	cout << setw(33) << setfill(probel) << probel;
	cout << setw(7) << setfill(c) << c << endl;
	cout << setw(33) << setfill(probel) << probel;
	cout << setw(7) << setfill(c) << c << endl;
}