/*
#include <ctime>
#include <iostream>
using namespace std;
void main()
{
	int size, mult = 1, sum = 0;
	int** A;
	cout << "Enter size ";
	cin >> size;
	srand(time(0));
	A = new int* [size];
	for (int i = 0; i < size; i++)
	{
		A[i] = new int[size];
		for (int j = 0; j < size; j++)
			A[i][j] = 1 + rand() % 10;
	}
	for (int** ptr = A; ptr != A + size; ++ptr)
	{
		for (int* it = *ptr; it != *ptr + size; ++it)
		{
			cout << "\t" << *it;
			if (*it % 2 == 0)
			{
				mult *= *it;
				sum += *it;
			}
		}
		cout << endl;
	}
	cout << "sum: " << sum << endl;
	cout << "mult: " << mult << endl;
	for (int k = 0; k < size; k++)
		delete[] A[k];
	delete[] A;
}
*/

	#include <ctime>
	#include <iostream>
	using namespace std;

	void main()
	{
		int variant;
		cout << "1. 7.1" << endl;
		cout << "2. 7.2" << endl;

		cin >> variant;

		switch (variant)
		{
		case 1: {
			setlocale(LC_ALL, "Russian");
			float size;
			int sum = 0, counter = 0;
			float midlle;
			cout << "������� ������ �������: ";
			cin >> size;
			float* A = new float[size];
			for (int i = 0; i < size; i++)
			{
				A[i] = rand() % 10;
			}

			cout << "������ A:" << endl;
			for (int i = 0; i < size; i++)
			{
				cout << A[i] << endl;
				sum = sum + A[i];
			}

			midlle = sum / size;
			cout << "C������ �����: " << midlle;

			for (int i = 0; i < size; i++)
			{
				if (A[i] > midlle) {
					counter += 1;
				}
			}

			cout << endl << "����� ������ ��� " << midlle << ": " << counter;
			delete[] A;
		}
		case 2: {
			setlocale(LC_ALL, "Russian");
			int row, col, counter = 0, counter_0 = 0, counter_max = 0, max;
			cout << "���-�� ����� ";
			cin >> row;
			cout << "���-�� �����. ";
			cin >> col;

			int** arr = new int* [row];

			for (int i = 0; i < row; i++)
			{
				arr[i] = new int[col];
			}
			//////////////���������//////////////////

			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					arr[i][j] = rand() % 10;
				}
			}
			///////////////�����////////////////

			for (int i = 0; i < row; i++)
			{

				for (int j = 0; j < col; j++)
				{
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}
			////////////////������� � ����� ������ ��� 0////////////////////////

			for (int i = 0; i < row; i++)
			{

				for (int j = 0; j < col; j++)
				{
					if (arr[i][j] == 0) {
						counter_0 += 1;
						break;
					}
				}
				if (counter_0 == 0)
					counter += 1;
				counter_0 = 0;
			}

			cout << "C���� ��� 0: " << counter << endl;
			///////////////////////������� �����////////////////////////////
			for (max = 9; counter_max < 2; max--) {
				counter_max = 0;
				for (int i = 0; i < row; i++)
				{
					for (int j = 0; j < col; j++)
					{
						if (arr[i][j] == max) {
							counter_max += 1;
						}
					}
				}
			}
			cout << "������������ �����: " << max + 1<< endl;
			///////////////�������� � ������/////////////////
			for (int i = 0; i < row; i++)
			{
				delete[] arr[i];
			}
			delete[] arr;
		}
		}
	}