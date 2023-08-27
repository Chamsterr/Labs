#include <iostream>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	float r, p, q;
	cout << "введите радиус шара r= ";
	cin >> r;

	cout << "введите первую диагональ ромба p= ";
	cin >> p;

	cout << "введите вторую диагональ ромба q= ";
	cin >> q;



	if ((2*r < p) && (2*r < q))
	{
		cout << "Пройдет :)" << endl;
	}
	else
	{
		cout << "Не пройдет :(" << endl;
	}
}