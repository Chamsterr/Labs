#include <iostream>

using namespace std;

int defaultparm(int a, int b, int c, int d, int e, int f = 6, int g = 7) {
	return (a + b + c + d + e + f + g) / 7;
}

int main() {
	cout << defaultparm(1, 2, 3, 4, 5) << " ";
	cout << defaultparm(1, 2, 3, 4, 5, 10, 11);
	return 0;
}