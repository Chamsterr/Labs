#include <iostream>
#include <iomanip> 

void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	float d, s;
	cout << "������� ����� ��������� d=";
	cin >> d;
	s = pow(d, 2) * 0.5;
	cout << "������� �������� ����� s=" << s << endl;
}