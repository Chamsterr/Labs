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
    /*циклом заполняем файл числами от 1 до 8*/
    for (i = 1; i < 9; i++) {
        fprintf(F1, "%d\n", i);
    }
    fclose(F1); //закрываем файл

    int k = 0;
    /*finput создаем для чтения нашего file.txt*/
    FILE* finput;
    int s;
    finput = fopen("file.txt", "r+");

    while ((fscanf(finput, "%d", &s) != EOF))
    {
        if (!finput) break;    //чтобы не делал лишнего
        k++;
    }
    int* c = (int*)malloc(k * sizeof(int));  /* malloc динамическое выделение памяти.
    будем предполагать, что неизвестно из скольки строк состоит файл.
    вычисляем размер памяти с помощью операции sizeof() */
    rewind(finput); //устанавливаем указатель на начало в файле,чтобы снова прочитать файл

    //создаем на запись второй файл F2,куда будем записывать прочитанный массив из finput
    cout << "Введите m:";
    cin >> m;

    FILE* F2;
    F2 = fopen("file2.txt", "wt");
    //записываем в F2 3 строчек
    for (i = 0; i < 3; i++)
    {
        fscanf(finput, "%d\n", &c[i]);
        fprintf(F2, "%d\n", c[i]);
    }
    fclose(finput); //закрываем файл

    free(c); //Высвобождение памяти 
    fclose(F2);//закрываем файл
    printf("DONE!");
    return 0;
}