#include <iostream>
#include <iomanip>
using namespace std;

void main() {
	setlocale(LC_CTYPE, "Russian");
	double P1, Q, n, P=0, d;
	cout << "������� ����������� ������ � ���� P=";
	cin >> P1;
	d = P1;
	P = P1;
	cout << "����������� ������� Q=";
	cin >> Q;
		for (n = 2; P<Q; n++)
		{
			d = d * 1.03;
			P = P + d;
			cout << "������� �� " << n << ": " << P << endl;
		}
		cout << "�� " << n -1  << " ���� ������� �������� ����������� ������� � ��������: " << P << "���";
}