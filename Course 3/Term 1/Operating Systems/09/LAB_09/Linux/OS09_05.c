#include <stdio.h>

int main() {
    FILE *file = fopen("OS09_05.txt", "r");
    if (file == NULL) {
        printf("Не удалось открыть файл\n");
        return 1;
    }

    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }

    printf("Количество строк в файле: %d\n", count);

    fclose(file);
    return 0;
}
