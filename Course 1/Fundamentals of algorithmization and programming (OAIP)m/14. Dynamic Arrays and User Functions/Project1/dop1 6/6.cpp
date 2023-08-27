#include <ctime>
#include <iostream>
using namespace std;
void var6_1();
void var6_2();
int main(void)
{
	setlocale(LC_ALL, "ru");
	int c;
	do
	{
		cout << "������� �����:\n1 6.1;\n1 6.2;\n3 �����.\n";
		cin >> c;
		switch (c)
		{
		case 1: var6_1(); break;
		case 2: var6_2(); break;
		case 3: break;
		}
	} while (c != 3);
}
void var6_1()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int size, i = 0, number = 0, k = 0;
	float* A, min = 100, sum = 0;
	cout << "������� ������ �������: ";
	cin >> size;
	A = new float[size];
	for (i = 0; i < size; i++)
	{
		A[i] = 0.01 * (rand() % 10000) - 30;
		cout << A[i] << endl;
		if (abs(A[i]) < min) //����� ������������ �� ������ �������� �������
		{
			min = A[i];
			number = i;
		}
	}
	for (i = 0; i < size; i++) //������ ������������� �������
	{
		if (A[i] < 0)
		{
			k = i;
			break;
		}
	}
	for (int j = k + 1; j < size; j++) //����� �������
	{
		sum += abs(A[j]);
	}
	cout << "����������� �� ������ ������� ������� A[" << number << "] = " << min << " = |" << abs(min) << "|" << endl;
	cout << "����� ������� ����� ������� �������������� ��������: " << sum << endl;
}
void var6_2()
{
	int i = 0, j = 0, pr = 1, mult = 1, counter = 0, number = 0, sd = 0;
	int const sz = 5;
	int	A[sz][sz] = { {3,-4,5,2,-8},{8,5,2,4,6},{9,3,-1,7,11},{4,6,1,9,7},{1,4,-2,9,10} };
	for (i = 0; i < sz; i++) //����� �������
	{
		for (j = 0; j < sz; j++)
		{
			cout << A[i][j] << '\t';
		}
		cout << '\n';
	}
	// 1. ���������� ������������ ��������� � ��� �������, ������� �� �������� ������������� ���������
	for (i = 0; i < sz; i++)
	{
		for (j = 0; j < sz; j++)
		{
			if (A[i][j] > 0) //������� ���-�� ������������� ��������� � ����� ����������� ��
			{
				++counter;
				pr *= A[i][j];
			}
		}
		if (counter == 5) //���� 5 ��������� �������������, �� ���������� �� ������������ � ����� ������������� ������
		{
			mult = pr;
			number = ++i;
			counter = 0;
			pr = 1;
		}
		else //����� ���������� ������������ � ������� � �������� ����� ������
		{
			pr = 1;
			counter = 0;
		}
		if (number != 0) cout << "������������ ��������� " << number << "-� ������: " << mult << endl; //���� ������ ���������, �� ������� �
	}
	// 2. ����� �������� ����� ���� ��������� ����������, ������������ ������� ��������� �������
	int k, max = 0;
	for (k = 1; k <= 3; k++) //������� ����� ���� ������� ���������
	{
		for (i = 0; i < sz; i++)
		{
			for (j = k; j < sz; j++)
			{
				if ((j - i) == k)
					sd += A[i][j];
			}
		}
		cout << "����� ��������� �" << k << ": " << sd << endl;
		if (sd > max)
			max = sd;
		sd = 0;
	}
	int l = 1;
	for (l = 1; l <= 3; l++) //������� ����� ���� ������� ���������
	{
		for (i = l; i < sz; i++)
		{
			for (j = 0; j < sz; j++)
			{
				if ((i - j) == l)
					sd += A[i][j];
			}
		}
		cout << "����� ��������� �" << k + l - 1 << ": " << sd << endl;
		if (sd > max)
			max = sd;
		sd = 0;
	}
	cout << "������������ ����� ��������� �����: " << max << endl;
}