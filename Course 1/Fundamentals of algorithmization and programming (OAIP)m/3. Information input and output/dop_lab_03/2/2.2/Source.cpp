#include <iostream>
#include <iomanip> 

void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	float y, x, y2, x2, s;
	cout << "введите y для первой точки";
	cin >> y;
	cout << "введите x для первой точки";
	cin >> x;
	cout << "введите y для второй точки";
	cin >> y2;
	cout << "введите x для второй точки";
	cin >> x2;
	s = sqrt(pow((x2 - x), 2) - pow((y2 - y), 2));
	cout <<"Расстояние равно" << s << endl;
}