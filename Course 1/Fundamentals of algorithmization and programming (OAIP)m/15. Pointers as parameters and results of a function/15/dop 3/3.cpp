#include <iostream>
using namespace std;
//����� 2
void zv(int dl, int z, string st)
{
	for (int i = 0; i <= dl - z; i++) {
		if (st[i] == '*') {
			i++;
			for (i; st[i] != '*'; i++)
				cout << st[i];
		}
	}
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	char st[] = "�������*���*��������";
	int dl, i, z = 0;
	cout << "�������� ������:�������*���*��������";
	cout << "\n����� ������:";
	dl = strlen(st);
	zv(dl, z, st);
}