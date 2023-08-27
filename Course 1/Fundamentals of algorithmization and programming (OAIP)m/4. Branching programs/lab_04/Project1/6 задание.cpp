#include <iostream>
int main() 
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	int a, b;
	cout << "Вы хотите купить велосипед? (1-да, 2-нет)";
	cin >> a;
	switch (a)
	{
	case 1: cout << "Какой? (1-Cannondale, 2-Trek, 3-Giant)";
		cin >> a;
		switch (a)
		{
		case 1: cout << "Прекрасный выбор"; break;
		case 2: cout << "Пойдет"; break;
		case 3: cout << "Может лучше пешком???"; break;
		default: cout << "Некорретный выбор";
			break;
		} break;
	case 2: cout << ("Подумайте еще раз.."); break;
	default: cout << ("Некорретный выбор"); break;
	}
	return 0;

}