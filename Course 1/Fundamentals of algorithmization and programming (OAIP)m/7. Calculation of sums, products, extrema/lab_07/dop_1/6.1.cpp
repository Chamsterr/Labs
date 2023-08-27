#include <iostream>
using namespace std;

void main() {
	setlocale(LC_CTYPE, "Russian");
	int num, counter, sum = 0;
	for (int counter = 1; true; counter++) {
		cout << "¬ведите num= (дл€ остановки наберите '00')";
		cin >> num;
		if (num % 2 == 0) {
			sum = sum + num;
		}

		if (num == 00) {
			break;
		}
	}
	cout << "—умма четных чисел sum=" << sum;
}