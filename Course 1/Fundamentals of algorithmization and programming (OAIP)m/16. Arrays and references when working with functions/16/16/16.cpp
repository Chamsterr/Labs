#include <iostream>
using namespace std;

void main(){
	setlocale(LC_ALL, "Russian");
	int row, col, counter = 0, counter_0 = 0, counter_max = 0, max, rmx = 0, rmn = -9, j_ = -2;
	float midlle, sum = 0;
	cout << "���-�� ����� ";
	cin >> row;
	cout << "���-�� �����. ";
	cin >> col;

	float** arr = new float* [row];

	for (int i = 0; i < row; i++)
	{
		arr[i] = new float[col];
	}
	//////////////���������//////////////////

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = (int)(((double)rand() /
				(double)RAND_MAX) * (rmx - rmn) + rmn);;
		}
	}
	///////////////�����////////////////

	for (int i = 0; i < row; i++)
	{

		for (int j = 0; j < col; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	////////////////������� � ����� ������ ��� 0////////////////////////

	for (int j = 0; j < col; j++)
	{

		for (int i = 0; i < row; i++)
		{
			if (arr[i][j] >= 0) {
				counter_0 += 1;
				break;
			}
		}
		if (counter_0 == 0) {
			counter += 1;
			j_ = j;
			break;
		}

	}
	if(counter > 0)
		cout << "������ ������������� ������� " << (j_ + 1) << endl;
	else
		cout << "���� "<< endl;

	///////////////////////������� ������� �� ��������////////////////////////////
	if(counter >  0){
		for (int i = 0; i < row; i++) {
		sum = sum + arr[i][j_];
		midlle = sum / (i+1);
		}
		cout << "������� �������������� ����� �� " << (j_ + 1) << " �������� - " << midlle << endl;
	}
	/////////////////////////////////////////////////
	
	for (int i = 0; i < row; i++)
	{

		for (int j = 0; j < col; j++)
		{
			arr[i][j] = arr[i][j] - midlle;
		}
	}
	/////////////////////////////////////////////////
	for (int i = 0; i < row; i++)
	{

		for (int j = 0; j < col; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	///////////////�������� � ������/////////////////
	for (int i = 0; i < row; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}