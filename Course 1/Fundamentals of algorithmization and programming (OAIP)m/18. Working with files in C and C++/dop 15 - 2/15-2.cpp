#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>  
#include <stdlib.h>
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    int i, m;
    FILE* F1;
    F1 = fopen("file.txt", "wt");
    if (!F1)
    {
        printf("Error!");
        return 0;
    }
    /*������ ��������� ���� ������� �� 1 �� 8*/
    for (i = 1; i < 9; i++) {
        fprintf(F1, "%d\n", i);
    }
    fclose(F1); //��������� ����

    int k = 0;
    /*finput ������� ��� ������ ������ file.txt*/
    FILE* finput;
    int s;
    finput = fopen("file.txt", "r+");

    while ((fscanf(finput, "%d", &s) != EOF))
    {
        if (!finput) break;    //����� �� ����� �������
        k++;
    }
    int* c = (int*)malloc(k * sizeof(int));  /* malloc ������������ ��������� ������.
    ����� ������������, ��� ���������� �� ������� ����� ������� ����.
    ��������� ������ ������ � ������� �������� sizeof() */
    rewind(finput); //������������� ��������� �� ������ � �����,����� ����� ��������� ����

    //������� �� ������ ������ ���� F2,���� ����� ���������� ����������� ������ �� finput
    cout << "������� m:";
    cin >> m;

    FILE* F2;
    F2 = fopen("file2.txt", "wt");
    //���������� � F2 3 �������
    for (i = 0; i < 3; i++)
    {
        fscanf(finput, "%d\n", &c[i]);
        fprintf(F2, "%d\n", c[i]);
    }
    fclose(finput); //��������� ����

    free(c); //������������� ������ 
    fclose(F2);//��������� ����
    printf("DONE!");
    return 0;
}