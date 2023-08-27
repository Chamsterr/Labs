#include "Hash_Twin_Chain.h"
#include <iostream>
using namespace std;
unsigned char rand8[256];
struct AAA
{
	int key;
	char* mas;
	AAA(int k, char* z) //конструктор с параметрами
	{
		key = k;
		mas = z;
	}
	AAA()//конструктор без параметров
	{
		key = 0;
		mas = (char*)"";
	}
};
//-------------------------------
int hf(void* d) // функци€ получени€ ключа
{
	double A;
	A = (sqrt(5.0f) - 1.0f) / 2.0f;
	std::cout << A;
	AAA* f = (AAA*)d;
	return  f->key * A;
}
//-------------------------------
void AAA_print(listx::Element* e) // функци€ вывода ключа и значений 
{
	std::cout<< std::endl << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->mas << " / ";
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int current_size = 7;
	cout << "¬ведите размер хеш-таблицы" << endl;
	cin >> current_size;
	for (int i = 0; i < 256; i++)
		rand8[i] = rand() % 255;
	hashTC::Object H = hashTC::create(current_size, hf); //—оздание таблицы 
	int choice;
	int k;
	for (;;)
	{
		system("cls");
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 2: {
			system("cls");
			AAA* a = new AAA;
			char* str = new char[20]; 
			cout << "введите номер" << endl;
			cin >> k;
			a->key = k;
			cout << "введите им€ " << endl;
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
			cout << "введите номер" << endl;
			cin >> k;
			b->key = k;
			H.deleteByData(b);
			system("pause");
		}
			  break;
		case 4: AAA * c = new AAA;
			system("cls");
			cout << "введите номер " << endl;
			cin >> k;
			c->key = k;
			if (H.search(c) == NULL)
				cout << endl << "Ёлемент не найдена" << endl;
			else
			{
				cout << endl << "Ёлемент с данным номером" << endl;
				AAA_print(H.search(c));
				cout << endl;
			}
			system("pause");
			break;
		}
	}
	return 0;
}