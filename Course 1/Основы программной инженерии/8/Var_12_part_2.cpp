#include <iostream>
using namespace std;
void main() {
	setlocale(LC_CTYPE, "Russian");
	char tmp[33];
	int A, B, C, n, p, t, m, q;

	cout << "������� 12\n\n";
	cout << "������� �2" << endl;

	cout << "������ ����� A="; cin >> A;
	C = A;

	_itoa_s(A, tmp, 2); cout << tmp << endl;

	cout << "������ ����� B="; cin >> B;

	_itoa_s(B, tmp, 2); cout << tmp << endl;

	/*������ 0*/
	cout << "������� � ������ ���� �������� "; cin >> n;
	t = n;
	n = n - 1;
	cout << "������� ������� ��� ������ "; cin >> p;
	cout << "���������" << endl;

	for (int i = 1; i <= p; i++) {

		C = C & (~(1 << n));

		_itoa_s(C, tmp, 2);

		n += 1;

		if (i == p) {

			cout << tmp << endl;

		}
	}

	/*������� 2*/

	int maskA = A;
	int maskB = ~maskA >> 1;

	cout << "������ �������" << endl;
	cout << "� ������ ���� ������" << endl; cin >> m;



	_itoa_s( ((B & (maskB << m) ) | (A  & maskA << m) ), tmp, 2);
														
	cout << " ��������� B=" << tmp << endl;
}

/*
&      |      ^      ~ 
x y z  x y z  x y z  ����������� 
0 1 0  1 0 1  0 0 0  �����
1 0 0  0 1 1  0 1 1
1 1 1  0 0 0  1 0 1
0 0 0  1 1 1  1 1 0
*/