#include <iostream>
#include <stdio.h>
using namespace std;
int flag = 1;

int comp(const void* i, const void* j)
{
	return *(int*)i - *(int*)j;
}

void ChangeFlag() {
	flag = !flag;
}


void main() {
	setlocale(LC_ALL, "Ru");
	int N, sum = 0, rnm = 100;

	cout << "Input N: ";
	cin >> N;

	int* arr = new int[N];
	int* arr_2 = new int[N];

	srand((unsigned)time(NULL));

	cout << "Вход:" << endl << "N = " << N << endl;
	for (int i = 0; i < N; i++) {
		arr[i] = rand() % rnm;
		cout << arr[i] << ' ';
	}
	cout << endl;

	qsort(arr, N, sizeof(int), comp);

	cout << "Выход: " << endl;
	for (int i = 0, j = N - 1, Z = 0; i < N; i++) {
		if (flag){
			arr_2[i] = arr[j];
			j--;
			sum += arr_2[i];
			ChangeFlag();
		}
		else{
			arr_2[i] = arr[Z];
			ChangeFlag();
			Z++;
		}

	}
	for (int i = 0; i < N; i++) {
		cout << arr_2[i] << ' ';
	}

	cout << endl << "Максимальная сумма чека: " << sum;

	delete []arr_2;
	delete []arr;
}