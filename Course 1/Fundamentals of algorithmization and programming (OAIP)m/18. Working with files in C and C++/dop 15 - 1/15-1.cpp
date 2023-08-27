#include <fstream>
#include <stdio.h>
#include <iostream>
int main()
{
    using namespace std;
    setlocale(LC_ALL, "");
    int rows, cols, c = 0;
    errno_t err;
    FILE* f;
    /*Создание файла*/
    err = fopen_s(&f, "a.txt", "w");
    if (err != 0)
    {
        perror("Невозможно создать файл\n");
        return EXIT_FAILURE;
    }
    /*Запись значений в файл*/
    printf("Введите кол строк\n");

    cin >> rows;

    printf("Введите кол столбцов\n");
    cin >> cols;
    fprintf(f, "%d ", rows);
    fprintf(f, "%d\n", cols);

    /*Создание матрицы и запись её в файл*/
    /*Присвоение значений массиву*/
    int** A; /* одна * когда массив простой, две * когда матрица, три * когад параллелепипед*/
    srand((unsigned)time(NULL));
    A = new int* [rows];
    for (int numb = 0; numb < rows; numb++) {
        A[numb] = new int[cols];
        for (int numb2 = 0; numb2 < cols; numb2++) {
            A[numb][numb2] = rand() % 10;
            fprintf(f, "%d ", A[numb][numb2]);
        }
        fprintf(f, "\n");
    }
    fclose(f);

    // 2 независамая часть

    printf("Введите k-утю строку\n");
    int k, k_start = 0, k_end = 0;
    cin >> k;

    ifstream input("a.txt"); //
    float ch;
    int Count = 0;
    while (input >> ch) //
        Count++;
    cout << "Чисел в файле : " << Count << endl;
    input.close();


    int* mass = new int[Count]; //создаём массив и указываем его размер
    ifstream file("a.txt"); //

    int cols2, rows2;

    file >> rows2; // читаем первую строку
    file >> cols2;// читаем вторую строку

    //чтение строк происходит последовательно

    cout << rows2 << " " << cols2 << endl;

    /*Создание файла*/

    errno_t file_b;
    FILE* b;

    file_b = fopen_s(&b, "b.txt", "w");
    if (file_b != 0)
    {
        perror("Невозможно создать файл\n");
        return EXIT_FAILURE;
    }

    /*т.к.размерность массива указывали переменной Count, а 2 значения из файла
    уже прочитаны, уменьшаем чтение в цикле на 2*/

    for (int i = 0; i < (Count - 2); i++) {
        k_start++;
        if (k_start > ((k - 1) * cols2) && k_end < cols2) {
            file >> mass[i];
            fprintf(b, "%d ", mass[i]);
            k_end++;
        }
        else {
            file >> mass[i];
        }
    }

    fclose(b);
    printf("Данные записаны в файл b.txt\n");
    return 0;
}