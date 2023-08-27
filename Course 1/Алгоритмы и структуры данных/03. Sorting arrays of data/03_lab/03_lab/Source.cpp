#include <iostream>
#include <ctime>

using namespace std;

void quicksort(int* mas, int first, int last) {     //функция сортировки
	int mid, count;
	int f = first, l = last;
	mid = mas[(f + l) / 2]; 				//вычисление опорного элемента
	do
	{
		while (mas[f] < mid) f++;
		while (mas[l] > mid) l--;
		if (f <= l) 				//перестановка элементов
		{
			count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) quicksort(mas, first, l);
	if (f < last) quicksort(mas, f, last);
}


void main() {
	setlocale(LC_ALL, "Ru");
	int size, rnm = 99;
	cout << "Введите размер массива: ";
	cin >> size;

	int *A = new int[size], *B = new int[size], *C = new int[size], *D = new int[size], *E = new int[size];

	cout << "Массив A: " << endl;
	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++){
		A[i] = rand() % rnm;
		B[i] = A[i];
		C[i] = A[i];
		D[i] = A[i];
		E[i] = A[i];
		cout << A[i] << " ";
	}

	//Пузырьковая
	unsigned int start_time_B = clock();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (B[j] > B[j + 1]) {
				int b = B[j];
				B[j] = B[j + 1]; 
				B[j + 1] = b;
			}	
		}
	}
	unsigned int end_time_B = clock();
	unsigned int search_time_B = end_time_B - start_time_B;

	cout << endl << "Отсортированный B: (пузырьковой сортировкой)" << endl;
	for (int i = 0; i < size; i++) {
		cout << B[i] << " ";
	}
	cout << "Время " << search_time_B << "мс";

	// Метод вставки 2
	unsigned int start_time_C = clock();
	for (int i = 1; i < size; ++i) {
		int k = i;
		while (k > 0 and C[k - 1] > C[k]) {
			int tmp = C[k - 1];
			C[k - 1] = C[k];
			C[k] = tmp;
			k -= 1;
		}
	}
	unsigned int end_time_C = clock();
	unsigned int search_time_C = end_time_C - start_time_C;
	

	cout << endl << "Отсортированный C: (методом вставки)" << endl;
	for (int i = 0; i < size; i++) {
		cout << C[i] << " ";
	}
	cout << "Время " << search_time_C << "мс";

	//метод выбора
	unsigned int start_time_D = clock();

	/*for (int i = 0; i < size - 1; i++) {
		int min = i;
		for (int j =i+1; j < size; j++)
			if (D[j] < D[min])
				min = j;
		int tmp = D[i];
		D[i] = D[min];
		D[min] = tmp;
	}
	*/

	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (D[j] < D[i])
				swap(D[j], D[i]);

	unsigned int end_time_D = clock();
	unsigned int search_time_D = end_time_D - start_time_D;
	

	cout << endl << "Отсортированный D: (методом выбора)" << endl;
	for (int i = 0; i < size; i++) {
		cout << D[i] << " ";
	}
	cout << "Время " << search_time_D << "мс";

	unsigned int start_time_E = clock();


	int first = 0, last = size - 1;
	quicksort(E, first, last);
	unsigned int end_time_E = clock();
	unsigned int search_time_E = end_time_E - start_time_E;


	cout << endl << "Отсортированный E: (быстрая сортировка)" << endl;
	for (int i = 0; i < size; i++) {
		cout << E[i] << " ";
	}
	cout << "Время " << search_time_E << "мс";
	delete[] A;
	delete[] B;
	delete[] C;
	delete[] D;
	delete[] E;

}