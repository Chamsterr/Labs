#include <iostream>
#include <vector>

using namespace std;

void main() {
	setlocale(LC_ALL, "Russian");
	int counter = 0 , a_counter = 0, max = 1;
	const int c_i = 3, c_j = 3;
	int a[c_i][c_j] = { { 10 , 2, 3 },{ 5, 5, 25 },{ 5, 10, 2 } };
	float h[c_i] = {};


	for (int i = 0; i < c_i; i++)
	{
		for (int j = 0; j < c_j; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << " " << endl;
	}
	
	for (int i = 0; i < c_i; i++) {
		for (int j = 0; j < c_j; j++) {
			if (counter % 4 == 0 && max < a[i][j]) {
				max = a[i][j];
			}
			counter += 1;
		}

	}
	cout << endl << max << endl;
	counter = 0;

	for (int i = 0; i < c_i; i++) {
		for (int j = 0; j < c_j; j++) {
			if (counter % 4 == 0) {
				h[a_counter] = a[i][j];
				a_counter += 1;
			}
			counter += 1;
		}

	}
	
	cout << endl << "Новый массив" << endl;
	for (int i = 0; i < a_counter; i++)
		cout << h[i] / max << endl;
}