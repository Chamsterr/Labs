#include <iostream>
#include <iomanip> 

void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	float p = 3.14, s, l, r;
	cout << "������� ����� ���������� l=";
	cin >> l;
	r = l / (2 * p);
	s = pow(r, 2) * p;
	cout << "������� ����� ����� s=" << s << endl;
}