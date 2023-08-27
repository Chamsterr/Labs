#include <iostream>
#include <iomanip>

void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	char c, probel; probel = ' ';
	cout << "Введите символ "; cin >> c;
	cout << setw(37) << setfill(probel) << probel;
	cout << setw(2) << setfill(c) << c << endl;
	cout << setw(34) << setfill(probel) << probel;
	cout << setw(8) << setfill(c) << c << endl;
	cout << setw(35) << setfill(probel) << probel;
	cout << setw(2) << setfill(c) << c;
	cout << setw(2) << setfill(probel) << probel;
	cout << setw(2) << setfill(c) << c;


}
