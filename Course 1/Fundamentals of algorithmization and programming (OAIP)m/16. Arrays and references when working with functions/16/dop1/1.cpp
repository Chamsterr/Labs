#include <ctime>
#include <iostream>
using namespace std;

void out(int** A, int size) {
	//�����
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << A[i][j] << "\t";
		}
		cout << "\n";
	}
	//
}
void function(int** A, int size) {
	//��������
	int k;
	bool b = false;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (A[i][j] < 0)
			{
				k = i;
				b = true;
				break;
			}
		}
		if (b == true)
		{
			cout << "������ ����� " << k + 1 << endl;
			break;
		}
	}

	//����������
	for (int i = 0; i < size; i++)
	{
		A[i][k] /= 2;
	}
	cout << endl;
	out(A, size);
}

int main() {
	setlocale(LC_ALL, "ru");
	int size;
	int** A;
	cout << "������� ������ ";
	cin >> size;
	srand(time(NULL));
	//��������� ������ {1}
	A = new int* [size];
	//��������� ������ {2} + ����������
	for (int i = 0; i < size; i++)
	{
		A[i] = new int[size];
		for (int j = 0; j < size; j++)
			A[i][j] = rand() % 21 - 15;
	}
	//
	out(A, size);
	function(A, size);

}