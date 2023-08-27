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
	bool g = false;
	int s;
	int prom;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (A[i][j] > 0)
			{
				s = i;
				g = true;
				break;
			}
		}
		if (g == true)
		{
			break;
		}
	}
	prom = s - 1;
	//����� ������
	cout << "������ �����: " << s + 1 << endl;
	//��������� ������
	if (s == 0)
	{
		cout << "������ ����������";
		return;
	}
	else
	{
		bool l = false;
		for (prom; l == false; prom++)
		{
			for (int j = 0; j < size; j++)
			{
				A[prom][j] = -A[prom][j];
			}
			l = true;
		}
		//�����
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << A[i][j] << "\t";
			}
			cout << "\n";
		}
	}
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
	delete[] A;
}