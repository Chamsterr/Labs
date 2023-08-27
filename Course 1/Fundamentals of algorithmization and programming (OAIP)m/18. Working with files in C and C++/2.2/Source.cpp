#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void main() {
	int x, j = 5, counter = 0;
	bool run = true;
	int arr[20];
	string path_f = "f.txt";
	string path_g = "g.txt";

	ifstream fin;
	ofstream fout;

	fin.open(path_f);
	if (!fin.is_open())
		cout << "Не удалось открыть файл";
	else {
		for (int i = 0; fin >> x; counter++) {
			if (x >0 && i >= 5 && i % 5 == 0) {
				i += 5;
			}
			if (x < 0 && j > 5 && j % 5 == 0) {
				j += 5;
			}
			if (x > 0) {
				arr[i] = x;
				i += 1;
			}
			else {
				arr[j] = x;
				j++;
			}
			
		}
	}
	fin.close();

	fout.open(path_g);
	for (int i = 0; i <= 19; i++) {
		fout << arr[i] << " ";
	}
	fout.close();
}