#include <iostream>
int main() 
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	int a, b;
	cout << "�� ������ ������ ���������? (1-��, 2-���)";
	cin >> a;
	switch (a)
	{
	case 1: cout << "�����? (1-Cannondale, 2-Trek, 3-Giant)";
		cin >> a;
		switch (a)
		{
		case 1: cout << "���������� �����"; break;
		case 2: cout << "������"; break;
		case 3: cout << "����� ����� ������???"; break;
		default: cout << "����������� �����";
			break;
		} break;
	case 2: cout << ("��������� ��� ���.."); break;
	default: cout << ("����������� �����"); break;
	}
	return 0;

}