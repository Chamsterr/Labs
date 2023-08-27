#include <iostream>
using namespace std;
void main() {
	int n = 100, n1, n2, n3;
	while (n < 1000)
	{
		n1 = int(n / 100);
		n2 = n / 10 - int((n1) * 10);
		n3 = n - (n1 * 100) - (n2 * (10));
		if (n1 < n2 && n2 < n3 && n1 < n3) {
			if (sqrt(n) - int(sqrt(n)) == 0) {
				if (0 != int(sqrt(n)) % 2) {
					cout << n << endl;
				}

			}
		}
		n = n + 1;
	}
	
}