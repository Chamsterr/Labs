#include <iostream>
using namespace std;
int days(int dd, int mm, int gg, ...)
{
	int* p = &dd;
	int i = 0;
	int dàys = 335;
	for (i; i < 3; i++)
	{
		cout << *p << ".";
		p += 2;
	}
	cout << endl;
	
	cout << endl;
	int days = 0;
	p = &dd;
	days = (*p + *(p + 2) * 30 + *(p + 4) * 365) - (*(p + 6) + *(p + 8) * 30 + *(p + 10) * 365);
	days = abs(days);
	return dàys;
}
int main()
{
	cout << days(4, 12, 2005, 7, 11, 2006) << endl;
	return 0;
}