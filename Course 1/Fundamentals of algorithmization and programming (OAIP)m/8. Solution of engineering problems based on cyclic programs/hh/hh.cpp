#include <iostream>
using namespace std;
// от 0 до 2

void main() {
	double e = 0.0001, x, a, b;

	cout << "a=";
	cin >> a;	
	cout << "b=";
	cin >> b;

	while (abs(a - b) > 2*e){
		x = (a + b) / 2;
		if ((exp(x) + x - 4) * (exp(a) + a - 4) <= 0)
			b = x;
		else
			a = x;
	}
		
	cout << x;
}