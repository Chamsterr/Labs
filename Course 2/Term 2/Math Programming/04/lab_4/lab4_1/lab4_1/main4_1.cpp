// --- main  
//    вычисление дистанции (расстояния) Левенштейна 
#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "Levenshtein.h"
#include <Windows.h>


using namespace std;

char* GenerateRandomString(int size)
{
	char* str = (char*)malloc(sizeof(char) * size);

	for (int i = 0; i < size; i++) {
		str[i] = rand() % 26 + 'a'; // 26 букв в алфавите
	}
	return str;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char* s1 = GenerateRandomString(300);
	cout << "S1: " << endl;
	for (int i = 0; i < 300; i++) {
		if (i % 50 == 0)
		{
			cout << "\n";
		}
		cout << s1[i];
	}
	cout << endl << endl;

	srand(time(NULL) + 1);
	char* s2 = GenerateRandomString(200);
	cout << "S2: " << endl;
	for (int i = 0; i < 200; i++) {
		if (i % 50 == 0)
		{
			cout << "\n";
		}
		cout << s2[i];
	}
	cout << endl << endl;

	clock_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	int lx = sizeof(s1);
	int ly = sizeof(s2);

	int s1_size[]{ 300 / 25, 300 / 20, 300 / 15, 300 / 10, 300 / 5, 300 / 2, 300 };
	int s2_size[]{ 200 / 25, 200 / 20, 200 / 15, 200 / 10, 200 / 5, 200 / 2, 200 };

	cout << "\n\n-- расстояние Левенштейна -----";
	cout << "\n\n--длина --- рекурсия -- дин.програм. ---\n";

	for (int i = 0; i < min(lx, ly); i++)
	{
		t1 = clock();
		levenshtein_r(s1_size[i], s1, s2_size[i], s2);
		t2 = clock();

		t3 = clock();
		levenshtein(s1_size[i], s1, s2_size[i], s2);
		t4 = clock();
		cout << right << setw(2) << s1_size[i] << "/" << setw(2) << s2_size[i]
			<< "        " << left << setw(10) << (t2 - t1)
			<< "   " << setw(10) << (t4 - t3) << endl;
	}
	system("pause");
	return 0;

}
