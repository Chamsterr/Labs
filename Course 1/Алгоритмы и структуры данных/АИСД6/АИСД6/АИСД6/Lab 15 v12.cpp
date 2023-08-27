#include "Hash_Twin_Chain.h"
#include <iostream>
using namespace std;
unsigned char rand8[256];
struct AAA
{
	int key;
	char* mas;
	AAA(int k, char* z) //����������� � �����������
	{
		key = k;
		mas = z;
	}
	AAA()//����������� ��� ����������
	{
		key = 0;
		mas = (char*)"";
	}
};
//-------------------------------
int hf(void* d) // ������� ��������� �����
{
	double A;
	A = (sqrt(5.0f) - 1.0f) / 2.0f;
	std::cout << A;
	AAA* f = (AAA*)d;
	return  f->key * A;
}
//-------------------------------
void AAA_print(listx::Element* e) // ������� ������ ����� � �������� 
{
	std::cout<< std::endl << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->mas << " / ";
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int current_size = 7;
	cout << "������� ������ ���-�������" << endl;
	cin >> current_size;
	for (int i = 0; i < 256; i++)
		rand8[i] = rand() % 255;
	hashTC::Object H = hashTC::create(current_size, hf); //�������� ������� 
	int choice;
	int k;
	for (;;)
	{
		system("cls");
		cout << "1 - ����� ���-�������" << endl;
		cout << "2 - ���������� ��������" << endl;
		cout << "3 - �������� ��������" << endl;
		cout << "4 - ����� ��������" << endl;
		cout << "0 - �����" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 2: {
			system("cls");
			AAA* a = new AAA;
			char* str = new char[20]; 
			cout << "������� �����" << endl;
			cin >> k;
			a->key = k;
			cout << "������� ��� " << endl;
			cin >> str;
			a->mas = str;
			H.insert(a);
		}
			  break;
		case 1:
			system("cls");
			H.Scan();
			system("pause");
			break;
		case 3: {	
			system("cls");
			AAA * b = new AAA;
			cout << "������� �����" << endl;
			cin >> k;
			b->key = k;
			H.deleteByData(b);
			system("pause");
		}
			  break;
		case 4: AAA * c = new AAA;
			system("cls");
			cout << "������� ����� " << endl;
			cin >> k;
			c->key = k;
			if (H.search(c) == NULL)
				cout << endl << "������� �� �������" << endl;
			else
			{
				cout << endl << "������� � ������ �������" << endl;
				AAA_print(H.search(c));
				cout << endl;
			}
			system("pause");
			break;
		}
	}
	return 0;
}