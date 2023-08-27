#include <iostream>
using namespace std;

int min6(int n, ...) {

	int min = 1000;
	int* p = &n;
	for (int i = 1; i <= n; i++) {
		*(++p);
		if (*p < min) {
			min = *p;
		}
	}
	return min;
}

double min6(double n, ...) {

	double min = 1000;
	double* p = &n;
	for (int i = 1; i <= n; i++) {
		*(++p);
		if (*p < min) {
			min = *p;
		}
	}
	return min;
}


void main() {

	cout << min6(5, 4, 5, 1, 2, 3) << endl;
	cout << min6(2.0, 34.22, 4445.4854, 5.54266);
}
