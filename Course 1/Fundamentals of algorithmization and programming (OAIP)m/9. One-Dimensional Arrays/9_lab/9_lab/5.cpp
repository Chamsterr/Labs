#include <iostream>
#include <ctime>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	const int N = 100;
	int n, i, sz, A[N], sred = 0;
	int rmn = 0, rmx = 99, kmin = 0;
	cout << "������� ������ ������� ";
	cin >> sz;
	cout << "������ �:" << endl;
	srand((unsigned)time(NULL));

	// ���������� ������
	for (i = 0; i < sz; i++)
	{
		A[i] = A[i] = rand() % rmx;
		cout << A[i] << endl;
	}
	cout << endl;

	// ���� ���
	for (i = 0; i < sz; i++)
	{
		if (A[i] < A[kmin])
			kmin = i;
	}
	cout << "��� ������� " << A[kmin] << endl;

	cout << endl;

	// ����� ���
	for (i = kmin; i <= sz; i++)
		A[i] = A[i + 1];
	sz--;

	// ������������� ����� ������ 
	for (i = 0; i < sz; i++)
	{
		cout << A[i] << endl;
	}

	// ������� ����� ����� 
	for (i = 0; i < sz; i++) 
	{
		sred = (sred + A[i]);
	}
	sred = sred / i;
	cout << "����= " << sred << endl;
	
	cout << endl;
	sz++;
	sz++;
	sz++;
	for (i = sz - 1; i >= 0; i--)
	{
		A[i] = A[i-3];
	}
	A[0] = sred;
	A[1] = sred;
	A[2] = sred;

	cout << endl;

	// ������������� ����� ������ 
	for (i = 0; i < sz; i++)
	{
		cout << A[i] << endl;
	}
}

