#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "������� n="<< endl;
	cin >> n;
	int sq[32][32];
	for (int i = 0; i < n; i++)//���������� ������� � �������� ���������
	{
		int a = i + 1;
		for (int j = 0; j < n; j++)
		{
			sq[i][j] = a;
			a++;
			if (a > n) a = 1;
		}
	}
	for (int i = 0; i < n; i++)//�����
	{
		for (int j = 0; j < n; j++)
			cout << sq[i][j] << ' ';
		cout << endl;
	}
	return 0;
}