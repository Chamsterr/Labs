#include <iostream>
#include <stdio.h>
using namespace std;

int comp(const void* i, const void* j)
{
	return *(int*)j - *(int*)i;
}

void main() {
	setlocale(LC_ALL, "Ru");
	int N, rnm = 10;

	cout << "Input N: ";
	cin >> N;

	int* arr = new int[N];

	srand((unsigned)time(NULL));

	cout << "¬ход:" << endl << "N = " << N << endl;
	for (int i = 0; i < N; i++) {
		arr[i] = rand() % rnm;
		cout << arr[i] << ' ';
	}
	cout << endl;

	qsort(arr, N, sizeof(int), comp);

	int counter = 0;
	for (int i = 0, counter_of_unique_number = 0; counter_of_unique_number < 3 && i!=N; i++) {
		counter_of_unique_number++;
		counter++;

		while (arr[i] == arr[i + 1]) {
			counter++;
			i++;
		}
	}
	cout << counter;
	delete[]arr;
}