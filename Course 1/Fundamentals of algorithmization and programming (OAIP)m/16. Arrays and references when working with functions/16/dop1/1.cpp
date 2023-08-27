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
	//
}
void function(int** A, int size) {
	//Проверка
	int k;
	bool b = false;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (A[i][j] < 0)
			{
				k = i;
				b = true;
				break;
			}
		}
		if (b == true)
		{
			cout << "Строка номер " << k + 1 << endl;
			break;
		}
	}

	//Уменьшение
	for (int i = 0; i < size; i++)
	{
		A[i][k] /= 2;
	}
	cout << endl;
	out(A, size);
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
			A[i][j] = rand() % 21 - 15;
	}
	//
	out(A, size);
	function(A, size);

}