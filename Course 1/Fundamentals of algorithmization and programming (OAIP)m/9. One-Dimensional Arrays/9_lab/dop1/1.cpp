#include <iostream>
#include <ctime>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	const int N = 366;
	int n, k = 1, i, sz, A[N], sred = 0, sum = 0, bigger = 0;
	int rmn = 0, rmx = 350, kmin = 0;
	cout << "Введите размер массива ";
	cin >> sz;
	cout << "Массив А:" << endl;
	srand((unsigned)time(NULL));

	for (i = 1; i < sz + 1; i++)
	{
		A[i] = rand() % rmx;
		sum = sum + A[i];
		cout << A[i] << endl;
		if (i % 7 == 0)
		{
			k = k + 1;
			cout << endl;
			cout << "Осадки " << sum << endl;

			if (bigger < sum)
				bigger = sum;
			sum = 0;
			cout << endl;
			cout << "Неделя" << k << endl;

		}

	}
	cout << "макс осадки = " << bigger;
}
