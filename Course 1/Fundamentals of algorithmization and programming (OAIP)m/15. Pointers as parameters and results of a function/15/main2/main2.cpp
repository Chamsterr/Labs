#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
//pochti norm

void proverka(int n1, int n2, char str[], char str2[]) {
	for (int i = 0; i < n2; i++) {
		if (str[i] == str2[i]) {
			cout << "��������� ������� ��� �������:" << i + 1 << endl;
		}
	}
}
void main()
{
	void(*proverk�) ();
	char str[1000] = " ", str2[1000] = " ";
	int n1, n2;
	setlocale(LC_CTYPE, "Russian");

	cout << "������� ����� ";
	cin >> str;


	cout << "������� ����� ";
	cin >> str2;

	n1 = strlen(str);
	n2 = strlen(str2);

	proverka(n1, n2, str, str2);

}