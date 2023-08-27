#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//int maxinfile(string path) {
	//fin.open
//}

void main() {
	setlocale(LC_ALL, "ru");
	string path_a, path_b, path_c, path_d;
	int x, y, z, max = 0, max_a = 0, max_b = 0, max_c = 0;

	int arr_a[6];
	int arr_b[6];
	int arr_c[6];

	path_a = "A.txt";
	path_b = "B.txt";
	path_c = "C.txt";
	path_d = "D.txt";

	ifstream fin;
	ofstream fout;


	fin.open(path_b);
	if (!fin.is_open()) {
		cout << "ошибка";
	}
	else {
		while (fin >> x) {
			for (int i = 0; i < 6; ++i) {
				arr_b[i] = x;
				fin >> x;
			}
		}
	}

	fin.close();

	fin.open(path_a);
	if (!fin.is_open()) {
		cout << "ошибка";
	}
	else {
		while (fin >> x) {
			for (int i = 0; i < 6; ++i) {
				arr_a[i] = x;
				fin >> x;
			}
		}
	}

	fin.close();

	fin.open(path_c);
	if (!fin.is_open()) {
		cout << "ошибка";
	}
	else {
		while (fin >> x) {
			for (int i = 0; i < 6; ++i) {
				arr_c[i] = x;
				fin >> x;
			}
		}
	}
	fin.close();



	fout.open(path_d);

	for (int i = 0; i < 6; ++i)
		fout << arr_a[i] << ", " << arr_b[i] << ", " << arr_c[i] << ", ";

	fout.close();
}