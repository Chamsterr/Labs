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
	bool g = false;
	int s;
	int prom;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (A[i][j] > 0)
			{
				s = i;
				g = true;
				break;
			}
		}
		if (g == true)
		{
			break;
		}
	}
	prom = s - 1;
	//Вывод строки
	cout << "Строка номер: " << s + 1 << endl;
	//Изменение знаков
	if (s == 0)
	{
		cout << "Замена невозможна";
		return;
	}
	else
	{
		bool l = false;
		for (prom; l == false; prom++)
		{
			for (int j = 0; j < size; j++)
			{
				A[prom][j] = -A[prom][j];
			}
			l = true;
		}
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
	delete[] A;
}