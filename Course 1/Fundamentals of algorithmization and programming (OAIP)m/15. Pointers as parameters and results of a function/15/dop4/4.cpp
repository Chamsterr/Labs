#include <iostream>
using namespace std;
void delB(int dl, char st[])
{
	int z = 0;
	for (int i = 0; i <= dl - z; i++) {
		if (st[i] == 'b') {
			i += 1;
			z += 1;
		}
		cout << st[i];
	}
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	char st[] = "babushka";
	int dl;
	cout << "�������� ������:babushka";
	cout << "\n����� ������:";
	dl = strlen(st);
	delB(dl, st);

}