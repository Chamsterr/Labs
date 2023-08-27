#include <iostream>
#include <ctime>

using namespace std;

void main() {
	setlocale(LC_ALL, "Ru");
	int N, number_0 = 0, number_1 = 1;
	bool run = 1, it = 0;
	cout << "Введите число N: ";
	cin >> N;
	unsigned int start_time = clock();

	for (int i = 0; i < N - 2; i++) {
		if (run) {
			number_0 = number_0 + number_1;
			run = 0;
			it = 1;
		}
		else {
			number_1 = number_1 + number_0;
			run = 1;
			it = 1;
		}
	}
	if (run == 1 && it == 1)
		cout << number_1 << endl;
	else
		cout << number_0 << endl;
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << "Расчетное время циклом: " << search_time << "мс";
}