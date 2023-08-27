#include <iostream>
#include <ctime>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	const int N = 100;
	int n, i, sz, A[N], sred = 0;
	int rmn = 0, rmx = 99, kmin = 0;
	cout << "Введите размер массива ";
	cin >> sz;
	cout << "Массив А:" << endl;
	srand((unsigned)time(NULL));

	// генирирует массив
	for (i = 0; i < sz; i++)
	{
		A[i] = A[i] = rand() % rmx;
		cout << A[i] << endl;
	}
	cout << endl;

	// ищет мин
	for (i = 0; i < sz; i++)
	{
		if (A[i] < A[kmin])
			kmin = i;
	}
	cout << "Мин элемент " << A[kmin] << endl;

	cout << endl;

	// гасит мин
	for (i = kmin; i <= sz; i++)
		A[i] = A[i + 1];
	sz--;

	// Пересчитывает новый массив 
	for (i = 0; i < sz; i++)
	{
		cout << A[i] << endl;
	}

	// считает сумму чисел 
	for (i = 0; i < sz; i++) 
	{
		sred = (sred + A[i]);
	}
	sred = sred / i;
	cout << "сред= " << sred << endl;
	
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

	// Пересчитывает новый массив 
	for (i = 0; i < sz; i++)
	{
		cout << A[i] << endl;
	}
}

