#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	int a, row, column;
	int B[20][20], S[20][20], R[20][20];
	errno_t err, er, e;
	FILE* f, * g, * k;
	err = fopen_s(&f, "first.txt", "w");
	cout << "������� ���������� ��������: ";
	cin >> column;
	cout << "������� ���������� �����: ";
	cin >> row; //��� ������ column = row1
	if (err != 0)
	{
		perror("���������� ������� ����\n");
		return EXIT_FAILURE;
	}
	for (int i = 0; i < row; i++) {

		for (int j = 0; j < column; j++) {
			B[i][j] = rand() % 99 + 1;
			fprintf(f, "%d, ", B[i][j]);
		}
		fputs("\n", f);
	}
	printf("������ �������� � ���� first.txt\n");

	er = fopen_s(&g, "second.txt", "w");
	if (er != 0)
	{
		perror("���������� ������� ����\n");
		return EXIT_FAILURE;
	}
	for (int i = 0; i < column; i++) {

		for (int j = 0; j < row; j++) {
			S[i][j] = rand() % 99 + 1;
			fprintf(g, "%d, ", S[i][j]);
		}
		fputs("\n", g);
	}
	printf("������ �������� � ���� second.txt\n");

	e = fopen_s(&k, "results.txt", "w");
	if (er != 0)
	{
		perror("���������� ������� ����\n");
		return EXIT_FAILURE;
	}

	for (int i = 0; i < row; i++) {

		for (int j = 0; j < column; j++) {

			R[i][j] = B[i][j] * S[j][i];
			fprintf(k, "%d, ", R[i][j]);
		}
		fputs("\n", k);
	}
	printf("������ �������� � ���� results.txt\n");
	fclose(k);
	fclose(g);
	fclose(f);
	return 0;
}