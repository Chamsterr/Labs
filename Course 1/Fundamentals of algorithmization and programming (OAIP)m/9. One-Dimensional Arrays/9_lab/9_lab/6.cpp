#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	const int N = 100;
	int n, i, sz, A[N], sred = 0, sred1 = 0, bigger;
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

	// ������� ����� ����� 
	for (i = 0; i < sz; i++)
	{
		sred = (sred + A[i]);
	}
	sred = sred / i;
	sred1 = sred;
	cout << endl;
	cout << "����= " << sred << endl;
	cout << endl;

	// ������������� ����� ������ 
	for (i = 0; i < sz; i++)
	{
		if (sred == A[i]) {
			cout << A[i];
			break;
		}

	}

	for (i = -1, bigger=1; i < sz; i++)
	{
		if (bigger > A[i + 1] && bigger < sred)
		{
			continue;
		}
		else if (bigger < A[i + 1] && A[i + 1] < sred)
		{
			bigger = A[i + 1];
		}
	}
	cout <<"����� ������� ����� " << bigger;
}
