#include <iostream>
#include <iomanip> 

void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	float y, x, y2, x2, s;
	cout << "������� y ��� ������ �����";
	cin >> y;
	cout << "������� x ��� ������ �����";
	cin >> x;
	cout << "������� y ��� ������ �����";
	cin >> y2;
	cout << "������� x ��� ������ �����";
	cin >> x2;
	s = sqrt(pow((x2 - x), 2) - pow((y2 - y), 2));
	cout <<"���������� �����" << s << endl;
}