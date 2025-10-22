#include <iostream>
#include <Windows.h>
#include <string>

#include <iostream>
#include <Windows.h>

DWORD PriorityStrToDWORD(int priority) {
    switch (priority) {
    case 64:
        return IDLE_PRIORITY_CLASS;
    case 16384:
        return BELOW_NORMAL_PRIORITY_CLASS;
    case 32:
        return NORMAL_PRIORITY_CLASS;
    case 32768:
        return ABOVE_NORMAL_PRIORITY_CLASS;
    case 128:
        return HIGH_PRIORITY_CLASS;
    case 256:
        return REALTIME_PRIORITY_CLASS;
    default:
        return Unknown;
    }
}

// Функция для запуска дочерного процесса
bool LaunchChildProcess(const wchar_t* applicationName, DWORD_PTR affinityMask, DWORD priority) {
    // Создайте структуру STARTUPINFO и инициализируйте ее.
    STARTUPINFO startupInfo;
    ZeroMemory(&startupInfo, sizeof(startupInfo));
    startupInfo.cb = sizeof(startupInfo);

    // Параметры запуска.
    startupInfo.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
    startupInfo.wShowWindow = SW_SHOW; // Опция для показа нового окна.

    // Создайте структуры PROCESS_INFORMATION, которые будут содержать информацию о созданном процессе.
    PROCESS_INFORMATION processInfo;
    ZeroMemory(&processInfo, sizeof(processInfo));

    // Запустите дочерний процесс.
    if (CreateProcess(applicationName, nullptr, nullptr, nullptr, TRUE, CREATE_NEW_CONSOLE, nullptr, nullptr, &startupInfo, &processInfo)) {
        if (SetProcessAffinityMask(processInfo.hProcess, affinityMask)) {
            std::wcout << L"Маска доступности процессоров успешно установлена." << std::endl;
        }
        else {
            std::cerr << "Ошибка при установке маски доступности процессоров. Код ошибки: " << GetLastError() << std::endl;
        }

        if (SetPriorityClass(processInfo.hProcess, priority)) {
            std::wcout << L"Приоритет процесса успешно установлен." << std::endl;
        }
        else {
            std::cerr << "Ошибка при установке приоритета процесса. Код ошибки: " << GetLastError() << std::endl;
        }

        // Закройте дескрипторы процесса и потока, чтобы избежать утечек ресурсов.
        CloseHandle(processInfo.hThread);
        CloseHandle(processInfo.hProcess);

        std::wcout << L"Дочерний процесс запущен в новом консольном окне." << std::endl;
        return true;
    }
    else {
        // Обработка ошибки, если запуск не удался.
        DWORD error = GetLastError();
        std::cerr << "Ошибка при запуске дочернего процесса. Код ошибки: " << error << std::endl;
        return false;
    }
}

int main(int argc, char* argv[]) {
    // Устанавливаем кодировку для ввода и вывода в русскую (Windows-1251)
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    if (argc != 4) {
        std::cout << "Использование: OS05_02 P1 P2 P3" << std::endl;
        return 1;
    }

    // Маска доступности процессоров
    // Как задётся пример у нас есть 4 ядерынй процессор. Мы хотим использовать 1 и 3 ядро, вводим число 10, битовое значение числа 10 -> 0101
    // 65535 - 16 потоков | 16383 - 14 | 4095 - 12 | 1023 - 10 | 255 - 8 | 63 - 6 | 15 - 4 | 3 - 2 
    DWORD_PTR affinityMask = static_cast<DWORD_PTR>(std::stoull(argv[1]));

    // Определите имя исполняемого файла, который вы хотите запустить в новом консольном окне.
    const wchar_t* applicationName = L"OS05_02x.exe";

    // Запустите два дочерних процесса
    if (
        LaunchChildProcess(applicationName, affinityMask, PriorityStrToDWORD(std::stoi(argv[2])))
        &&
        LaunchChildProcess(applicationName, affinityMask, PriorityStrToDWORD(std::stoi(argv[3])))
        )
    {
        std::wcout << L"Два дочерних процесса успешно запущены." << std::endl;
    }

    return 0;
}