#include <iostream>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	float a, b;
	cout << "������� ���" << endl;
	cin >> a;
	b = a / 4;
	if (b == int(b))
	{
		cout << "��� ����������" << endl;
	}
	else
	{
		cout << "��� �� ����������" << endl;
	}
}