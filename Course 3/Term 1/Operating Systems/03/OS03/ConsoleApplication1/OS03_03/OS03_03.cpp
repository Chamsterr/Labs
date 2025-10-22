#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
#include <fstream>

int main() {
    HANDLE hSnap;
    PROCESSENTRY32 pe32;

    // Открываем файл для записи информации о процессах
    std::ofstream outputFile("processes.txt");

    if (!outputFile.is_open()) {
        std::cerr << "Ошибка при открытии файла для записи." << std::endl;
        return 1;
    }

    system("chcp 1251>null");
    // Создаем снимок всех процессов в системе
    hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnap == INVALID_HANDLE_VALUE) {
        std::cerr << "Ошибка при создании снимка процессов: " << GetLastError() << std::endl;
        outputFile.close();
        return 1;
    }

    // Устанавливаем размер структуры PROCESSENTRY32
    pe32.dwSize = sizeof(PROCESSENTRY32);

    // Получаем информацию о первом процессе
    if (!Process32First(hSnap, &pe32)) {
        std::cerr << "Ошибка при получении информации о первом процессе: " << GetLastError() << std::endl;
        CloseHandle(hSnap);
        outputFile.close();
        return 1;
    }

    // Выводим информацию о каждом процессе в файл
    do {
        outputFile << "ID процесса: " << pe32.th32ProcessID << std::endl;

    } while (Process32Next(hSnap, &pe32));

    // Закрываем дескриптор снимка процессов
    CloseHandle(hSnap);

    // Закрываем файл
    outputFile.close();

    // Открываем файл в ассоциированной программе для просмотра
    system("start notepad processes.txt");

    return 0;
}