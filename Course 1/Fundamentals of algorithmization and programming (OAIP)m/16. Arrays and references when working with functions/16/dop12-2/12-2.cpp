//lab 16 v 12 zad 2
#include <iostream>
using namespace std;
void min(int A[], int size)
{
	//�����
	for (int i = 0; i < size; i++)
	{
		cout << A[i] << "\t";
	}
	cout << endl;
	//��������
	for (int i = 0; i < size; i++)
	{
		if (A[i]<0)
		{
			cout << "������������� �������� ����" << endl;
		}
	}
	//��������
	for (int i = 0; i < size; i++)
	{
		if (A[i] < 0)
		{
			int k = i;
			for (int j = k; j < size; j++)
			{
				A[j] = A[j + 1];
			}
			size--;
		}
	}
	//�����
	for (int i = 0; i < size; i++)
	{
		cout << A[i] << "\t";
	}
	cout << endl;

}
void main()
{
	setlocale(LC_ALL, "ru");
	int s;
	const int size = 6;
	int A[] = { 5, 4.1, -3, 0.2, -11, 3 };
	min(A, size);
}