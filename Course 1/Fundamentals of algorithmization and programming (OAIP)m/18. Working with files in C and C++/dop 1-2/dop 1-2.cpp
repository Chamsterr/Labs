#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int a, k, z = 0, m = 0; errno_t err, fl;
	char pd;
	FILE* f;
	FILE* g;
	err = fopen_s(&f, "f.txt", "w");
	fl = fopen_s(&g, "g.txt", "w");
	cout << "Введи какому числу должно быть кратно: ";
	cin >> k;
	if (err != 0)
	{
		perror("Невозможно создать файл\n");
		return EXIT_FAILURE;
	}
	for (a = 0; a < 30; a += 1)
	{

		m = -60 + rand() % 99;
		if (m >= 10 || m <= -10) {

			fprintf(f, "%d, ", m);
			if (m % k == 0) {
				fprintf(g, "%d, ", m);
			}

		}
	}
	for (int k = 1; k <= ftell(f); k++)
	{
		fread((void*)&pd, sizeof(char), 1, f);
		if (pd != ' ') {
			cout << pd;
		}
	}
	printf("Данные записаны в файл f.txt\n");
	printf("Данные записаны в файл g.txt\n");
	fclose(f);
	fclose(g);
	return 0;
}