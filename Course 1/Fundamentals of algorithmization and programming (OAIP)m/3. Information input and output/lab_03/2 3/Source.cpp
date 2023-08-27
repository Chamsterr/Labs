#include <iostream>
#include <iomanip> 

void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	float p = 3.14, s, l, r;
	cout << "¬ведите длину окружности l=";
	cin >> l;
	r = l / (2 * p);
	s = pow(r, 2) * p;
	cout << "ѕлощадь круга равна s=" << s << endl;
}