#include <iostream> 
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int A, i; char tmp[33];
	cout << "������� ����� ";
	cin >> A;
	_itoa_s(A, tmp, 2);

	cout << "����� � �������� ���� = " << tmp << endl;
	if ((A & 3) == 0)
		cout << "����� ������ 4" << endl;
	else
		cout << "����� �� ������ 4" << endl;
}
