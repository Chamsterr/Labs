#include <iostream>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	float r, p, q;
	cout << "������� ������ ���� r= ";
	cin >> r;

	cout << "������� ������ ��������� ����� p= ";
	cin >> p;

	cout << "������� ������ ��������� ����� q= ";
	cin >> q;



	if ((2*r < p) && (2*r < q))
	{
		cout << "������� :)" << endl;
	}
	else
	{
		cout << "�� ������� :(" << endl;
	}
}