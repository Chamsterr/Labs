#include <iostream>
#include <ctime>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	const int N = 366;
	int n, m = 0, k = 0, i, sz, sred = 0, sum = 0, bigger = 0;
	int rmn = 0, rmx = 350, kmin = 0;
	int A[] = { 1, 2, 4, 5, 1, 4, 2, 7, 9, 10, 10, 9, 7};
	//13
	cout << "¬ведите размер массива ";
	cin >> sz;


	for (i = 0; i < sz; i++)
	{
		for (n = 0; n < sz; n++)
		{
			if (A[i] == A[n] && i != n);
			else
				m = m + 1;

		}
	}
	cout << sz - ((i * n) - m);
}	