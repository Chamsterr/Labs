// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89

#include <iostream>
#include <ctime>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	const int N = 366;
	int n, m = 0, k = 0, i, sz, sred = 0, sum = 0, bigger = 0, A[N];
	int rmn = 1, rmx = 100, kmin = 0, per;
	bool run = true;
	int F[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

	cout << "������� ������ ������� ";
	cin >> sz;
	srand((unsigned)time(NULL));

	// ���������� ������
	for (i = 0; i < sz; i++)
	{
		A[i] = (int)(((double)rand() /
			(double)RAND_MAX) * (rmx - rmn) + rmn);
		cout << A[i] << endl;
	}
	cout << endl;

	for (i = 0; i < sz; i++)
	{
		for (n = 0; n < 13; n++)
		{
			if (A[i] == F[n])
			{
				per = F[n];
				run = false;
				break;
			}
		}
	}

	if (run == true)
		cout << "��� =(";
	else if (run = false)
		cout << "���� = " << per;

}