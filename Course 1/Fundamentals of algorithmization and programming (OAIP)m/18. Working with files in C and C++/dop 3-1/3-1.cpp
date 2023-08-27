#include <stdio.h>
#include <iostream>
int main()
{
	setlocale(LC_ALL, "");
	int a, m = 5, n = 5;
	int B[20][20];
	errno_t err;
	FILE* f, * h;
	err = fopen_s(&f, "in.txt", "w");
	if (err != 0)
	{
		perror("Невозможно создать файл\n");
		return EXIT_FAILURE;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			B[i][j] = rand() % 99 + 1;
			fprintf(f, "%d, ", B[i][j]);
		}

		fputs("\n", f);
	}
	printf("Данные записаны в файл in.txt\n");
	fclose(f);
	err = fopen_s(&h, "transporant.txt", "w");
	if (err != 0)
	{
		perror("Невозможно создать файл\n");
		return EXIT_FAILURE;
	}

	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < m; j++) {

			fprintf(h, "%d, ", B[j][i]);
		}

		fputs("\n", h);
	}
	printf("Данные записаны в файл transporant.txt\n");
	fclose(h);
	return 0;
}