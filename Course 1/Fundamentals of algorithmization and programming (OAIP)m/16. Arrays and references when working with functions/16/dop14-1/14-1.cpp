#include <ctime>
#include <iostream>
using namespace std;

void out(int** A, int size) {
	//Вывод
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << A[i][j] << "\t";
		}
		cout << "\n";
	}
}
void function(int** A, int size) {
	int k = 0, s;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (A[j][i] > 0)
			{
				k++;
				s = i;
			}
			if (k == size)
			{
				cout << "Столбец номер " << s + 1 << endl;
				break;
			}
		}
		if (k == size)
		{
			break;
		}
		k = 0;
	}
	if (s == 0)
	{
		cout << "Замена знаков невозможна" << endl;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			A[i][s - 1] = -A[i][s - 1];
		}
		out(A, size);
	}

}

int main() {
	setlocale(LC_ALL, "ru");
	int size;
	int** A;
	cout << "Введите размер ";
	cin >> size;
	srand(time(NULL));
	//Выделение памяти {1}
	A = new int* [size];
	//Выделение памяти {2} + Заполнение
	for (int i = 0; i < size; i++)
	{
		A[i] = new int[size];
		for (int j = 0; j < size; j++)
			A[i][j] = rand() % 100 - 15;
	}
	//
	out(A, size);
	function(A, size);
}