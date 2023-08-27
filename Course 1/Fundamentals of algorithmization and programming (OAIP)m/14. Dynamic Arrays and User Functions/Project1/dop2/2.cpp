#include <iostream>
#include <iomanip>

void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;

	int c = 10, m;
	int* a = new int[c];
	int i, j, nmin = -10, nmax = 10, max = 0, min = 0, f, t;
	do {
		cout << endl;
		cout << "1- 2,1" << endl;
		cout << "2- 2.2" << endl;
		cout << "3-Выход" << endl;
		cin >> m;
		switch (m)
		{
		case 1:
			for (i = 0; i < c; i++)
			{
				a[i] = (int)(((double)rand() /
					(double)RAND_MAX) * (nmax - nmin) + nmin);
				cout << " " << a[i];
			}
			cout << endl;
			for (int i = 0; i < c; i++) {
				if (a[i] < min)
					min = a[i];
			}
			if (min < 0) {
				for (i = 0; i < c; i++)
				{
					if (a[i] < 0)
					{
						if (a[i] > a[max])
							max = i;
					}
				}
				cout << "Есть отрицательный элемент" << endl;
				cout << "max: " << a[max] << endl;
			}
			else {
				cout << "Нет значений меньше 0" << endl;
			}
			delete[] a;
			break;
		case 2:
			const int x = 5;
			const int y = 4;
			int k[x][y];
			for (i = 0; i < x; i++)
			{
				for (j = 0; j < y; j++)
				{
					k[i][j] = (int)(((double)rand() /
						(double)RAND_MAX) * (nmax - nmin) + nmin);
					if (j % 5 == 0)
						cout << endl;
					cout << setw(3) << k[i][j];
				}
			}
			cout << endl;
			for (i = 0; i < x; i++)
			{
				for (j = 0; j < y; j++)
				{
					if (k[i][j] > max) {
						max = k[i][j];
						f = i, t = j;
					}
				}
			}
			int p;
			p = k[0][0];
			k[0][0] = max;
			k[f][t] = p;
			for (i = 0; i < x; i++)
			{
				for (j = 0; j < y; j++)
				{
					if (j % 5 == 0)
						cout << endl;
					cout << setw(3) << k[i][j];
				}
			}
			cout << endl;
			cout << "max: " << max << endl;
			break;
		}
	} while (m != 3);
}