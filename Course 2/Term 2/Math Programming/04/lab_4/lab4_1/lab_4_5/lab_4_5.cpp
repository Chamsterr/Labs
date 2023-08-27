#include<iostream>
#include<iomanip>
#include"LCH.h"
#include"LCS.h"
using namespace std;
void main() {
	setlocale(LC_ALL, "rus");
	char z[100] = "";
	char x1[] = "QVTWNHO",
		y1[] = "RQTWYK";
	clock_t start1 = clock();
	int l = lcsd(x1, y1, z);
	clock_t end1 = clock();
	std::cout << std::endl
		<< "-- ���������� ����� �������������������� - LCS(������������"
		<< "����������������)" << std::endl;
	std::cout << std::endl << "����������������� X: " << x1;
	std::cout << std::endl << "����������������� Y: " << y1;
	std::cout << std::endl << "                LCS: " << z;
	std::cout << std::endl << "          ����� LCS: " << l;
	std::cout << std::endl;

	system("pause");
	///////////////////////////////////////////////////////////////////////////////////////////
	char X[] = "QVTWNHO", Y[] = "RQTWYK";
	std::cout << std::endl << "-- ���������� ����� LCS ��� X � Y(��������)";
	std::cout << std::endl << "-- ������������������ X: " << X;
	std::cout << std::endl << "-- ������������������ Y: " << Y;
	clock_t start2 = clock();
	int s = lcs(
		sizeof(X) - 1,  // �����   ������������������  X   
		"QVTWNHO",       // ������������������ X
		sizeof(Y) - 1,  // �����   ������������������  Y
		"RQTWYK"       // ������������������ Y
	);
	clock_t end2 = clock();
	std::cout << std::endl << "-- ����� LCS: " << s << std::endl;
	cout << "����� ����������� �� ���������� ����� ���������������������(��): " << ((float)start1 - (float)end1) / CLOCKS_PER_SEC << " ���.\n";
	cout << "����� ����������� �� ���������� ����� ���������������������(��������): " << ((float)start2 - (float)end2) / CLOCKS_PER_SEC << " ���.\n";
	system("pause");
}