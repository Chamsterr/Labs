#include <iostream>
#include <cmath>
using namespace std;

void main() {
	setlocale(LC_ALL, "Ru");
	float max_range, min_range = 1, N;
	int var, range, i = 1;
	bool run = 1;
	cout << "������� N: ";
	cin >> N;
	max_range = N;
	range = round(max_range / 2);
	cout << range << endl;
	while(run){
		cout << "�������� �������� (1.���� 2.����� 3.������): ";
		cin >> var;
		switch (var) {
		case 1:
			min_range = range;
			range = round((min_range + max_range)/2);
			cout << range << endl;
			continue;
		case 2:
			max_range = range;
			range = (min_range + max_range) / 2;
			cout << range << endl;
			continue;
		case 3:
			cout << N << endl;
			while (N / 2) {
				N = round (N / 2);
				cout << N << endl;
				if (N == 1)
					break;
				++i;
			}
			cout <<"������������ ���������� �����: " << i;
			run = false;
		}

	}
}