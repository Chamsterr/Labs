#include<iostream>
#include <cctype>
#include "difLat.h"
#include "difRu.h"
#include "numcode.h"

void main(){
	using namespace std;
	setlocale(LC_ALL, "Russian");
	char title_letter, lower_letter, code_title_letter, code_lower_letter;
	int variant, difference;
	bool run = true;

	while(run) {

		cout << "\n��������, ��� ���������� ������� � ����� ���������:" << endl;
		cout << "1.����������� ������� �������� ����� � Windows-1251 ����� ���������� �������� � ��������� � �������� ���������; " << endl;
		cout << "2.����������� ������� �������� ����� � Windows-1251 ����� �������� �������� � ��������� � �������� ���������; " << endl;
		cout << "3.����� � ������� ���� �������, ���������������� ��������� �����;" << endl;
		cout << "4.����� �� ���������." << endl;

		cin >> variant;

		switch (variant)
		{
		case 1:
			difLat();
			continue;

		case 2:
			difRu();
			continue;

		case 3:
			numcode();
			continue;

		case 4:
			run = false;
			break;

		default:
			cout << "������� ���������� �������" << endl;
			break;
		}
	}
}