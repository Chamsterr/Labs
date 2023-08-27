#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	int a[32][32];
	int m[16][16];
	int i, j, nmax = 10, nmin = -10, sum = 0, k = 0, l = 0, c = 0, n;
	cout << "¬ведите n= ";
	cin >> n;
	for (i = 0; i < (2 * n); i++)
	{
		for (j = 0; j < (2 * n); j++)
		{
			a[i][j] = (int)(((double)rand() /
				(double)RAND_MAX) * (nmax - nmin) + nmin);
			((i >= n) && (j >= n)) ? m[i - n][j - n] = a[i][j] : j = j;
			if (j % 5 == 0)
				cout << endl;
			cout << setw(3) << a[i][j];
		}
	}
	cout << endl;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[2 * n - n + (i)][2 * n - n + (j)] = a[i][j];
			a[i][j] = m[i][j];
			m[i][j] = a[i][2 * n - n + (j)];
			a[i][2 * n - n + (j)] = a[2 * n - n + (i)][j];
			a[2 * n - n + (i)][j] = m[i][j];
		}
	}
	for (i = 0; i < (2 * n); i++)
	{
		for (j = 0; j < (2 * n); j++)
		{
			if (j % 5 == 0)
				cout << endl;
			cout << setw(3) << a[i][j];
		}
	}
}