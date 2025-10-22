#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Ошибка: Неверное количество аргументов\n");
        return 1;
    }

    int row = atoi(argv[1]);
    FILE* file = fopen("OS09_05.txt", "r");
    FILE* output_file;
    if (row % 2 == 0) {
        output_file = fopen("OS09_06_2.txt", "w");
    }
    else {
        output_file = fopen("OS09_06_1.txt", "w");
    }

    char line[256];
    int line_number = 1;
    while (fgets(line, sizeof(line), file)) {
        if (line_number % 4  == row % 4) {
            fputs(line, output_file);
        }
        line_number++;
    }

    fclose(file);
    fclose(output_file);

    printf("Файл создан.\n");

    return 0;
}
