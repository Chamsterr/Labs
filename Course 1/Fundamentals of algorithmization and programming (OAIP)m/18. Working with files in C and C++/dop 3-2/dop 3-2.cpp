#include <stdio.h>
#include <iostream>
int main()
{
	setlocale(LC_ALL, "");
	int a; errno_t err;
	int A[] = { 1,2,3,4,5 };
	int B[] = { 6,7,8,9,10 };
	int C[] = { 11,12,13,14,15 };
	FILE* f, * s, * t, * d;
	err = fopen_s(&f, "a.txt", "w");
	if (err != 0)
	{
		perror("Невозможно создать файл\n");
		return EXIT_FAILURE;
	}
	for (int i = 0; i < 5; i++)
	{
		fprintf(f, "%d, ", A[i]);
	}
	printf("Данные записаны в файл A.txt\n");
	fclose(f);

	err = fopen_s(&s, "b.txt", "w");
	if (err != 0)
	{
		perror("Невозможно создать файл\n");
		return EXIT_FAILURE;
	}
	for (int i = 0; i < 5; i++)
	{
		fprintf(s, "%d, ", B[i]);
	}
	printf("Данные записаны в файл B.txt\n");
	fclose(s);

	err = fopen_s(&t, "c.txt", "w");
	if (err != 0)
	{
		perror("Невозможно создать файл\n");
		return EXIT_FAILURE;
	}
	for (int i = 0; i < 5; i++)
	{
		fprintf(t, "%d, ", C[i]);
	}
	printf("Данные записаны в файл C.txt\n");
	fclose(t);

	err = fopen_s(&d, "d.txt", "w");
	if (err != 0)
	{
		perror("Невозможно создать файл\n");
		return EXIT_FAILURE;
	}
	for (int i = 0; i < 5; i++)
	{
		fprintf(d, "%d, ", A[i]);
		fprintf(d, "%d, ", B[i]);
		fprintf(d, "%d, ", C[i]);

	}
	printf("Данные записаны в файл D.txt\n");
	fclose(d);
	return 0;
}