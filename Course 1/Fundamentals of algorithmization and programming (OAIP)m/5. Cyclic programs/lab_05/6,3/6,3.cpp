#include <iostream>
#include <string> 

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Russian");
	char c;
	string p;
	int x = 0, s = 0, k, n;
	cout << "введите k=";
	cin >> k;
	while (s != k)
	{
		n = pow(2, x);
		p = p + to_string(n);
		s = s + 1;
		x = x + 1;
	}
	s = s - 1;
	cout << p << endl;
	c = p[s];
	cout << k <<"-ая цифра =" << c;
}
 