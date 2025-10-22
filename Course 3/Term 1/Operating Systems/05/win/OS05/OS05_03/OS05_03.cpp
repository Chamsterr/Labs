#include <iostream>
#include <Windows.h>
#include <thread>
#include <string>

// Потоковая функция для дочерних потоков
void TA(int priorityT, DWORD priorityP, DWORD_PTR affinityMask, HANDLE hConsole, DWORD Color) {

    if (!SetThreadPriority(GetCurrentThread(), priorityT)) {
        std::cerr << "Ошибка при установке приоритета для потока. Код ошибки: " << GetLastError() << std::endl;
    }

    if (!SetThreadAffinityMask(GetCurrentThread(), affinityMask)) {
        std::cerr << "Ошибка при установке маски доступности процессоров. Код ошибки: " << GetLastError() << std::endl;
    }
    if (!SetPriorityClass(GetCurrentProcess(), priorityP)) {
        std::cerr << "Ошибка при установке приоритета для процесса. Код ошибки: " << GetLastError() << std::endl;

    }


    for (int i = 1; i <= 1000000; ++i) {
        if (i % 1000 == 0) {
            Sleep(200);
            SetConsoleTextAttribute(hConsole, Color);
            std::cout << "Итерация: " << i
                << " | ID процесса: " << GetCurrentProcessId()
                << " | ID потока: " << GetCurrentThreadId()
                << " | Приоритет процесса: " << GetPriorityClass(GetCurrentProcess())
                << " | Приоритет потока: " << GetThreadPriority(GetCurrentThread())
                << " | Назначенный процессор: " << GetCurrentProcessorNumber() << std::endl;
        }
    }
}

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

int main(int argc, char* argv[]) {
    // Устанавливаем кодировку для ввода и вывода в русскую (Windows-1251)
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    if (argc != 5) {
        std::cout << "Использование: OS05_03 P1 P2 P3 P4" << std::endl;
        return 1;
    }

    // Параметры, переданные через командную строку.
    int P1 = std::stoi(argv[1]);
    int P2 = std::stoi(argv[2]);
    int P3 = std::stoi(argv[3]);
    int P4 = std::stoi(argv[4]);

    // Вывод параметров.
    std::cout << "P1 (Маска доступности процессоров): " << P1 << std::endl;
    std::cout << "P2 (Приоритет процесса): " << P2 << std::endl;
    std::cout << "P3 (Приоритет первого дочернего потока): " << P3 << std::endl;
    std::cout << "P4 (Приоритет второго дочернего потока): " << P4 << std::endl;

    //Для цвета
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //affinityMask
    DWORD_PTR affinityMask = static_cast<DWORD_PTR>(std::stoull(argv[1]));

    // Создание и запуск двух дочерних потоков с заданными приоритетами.
    std::thread thread1(TA, P3, PriorityStrToDWORD(std::stoull(argv[2])), affinityMask, hConsole, FOREGROUND_GREEN);
    std::thread thread2(TA, P4, PriorityStrToDWORD(std::stoull(argv[2])), affinityMask, hConsole, FOREGROUND_RED);

    // Ожидание завершения дочерних потоков.
    thread1.join();
    thread2.join();

    return 0;
}


/*

Функция SetThreadPriority в Windows принимает одно из следующих числовых значений для установки приоритета потока:

В Windows функция SetThreadPriority также может использовать числовые значения для установки приоритета потока. Вот числовые эквиваленты приоритетов:

THREAD_PRIORITY_TIME_CRITICAL равен 15.
THREAD_PRIORITY_HIGHEST равен 2.
THREAD_PRIORITY_ABOVE_NORMAL равен 1.
THREAD_PRIORITY_NORMAL равен 0.
THREAD_PRIORITY_BELOW_NORMAL равен -1.
THREAD_PRIORITY_LOWEST равен -2.
THREAD_PRIORITY_IDLE равен -15.
THREAD_MODE_BACKGROUND_BEGIN равен 16.
THREAD_MODE_BACKGROUND_END равен 15.



Функция SetPriorityClass в Windows принимает одно из следующих числовых значений для установки класса приоритета процесса:

IDLE_PRIORITY_CLASS (64): Низкий приоритет процесса. Процесс с этим классом приоритета будет выполняться только в том случае, если нет активных процессов с более высоким приоритетом.

BELOW_NORMAL_PRIORITY_CLASS (16384): Ниже нормального приоритета процесса. Процесс будет иметь приоритет чуть ниже нормального.

NORMAL_PRIORITY_CLASS (32): Нормальный приоритет процесса. Это значение по умолчанию для большинства процессов.

ABOVE_NORMAL_PRIORITY_CLASS (32768): Выше нормального приоритета процесса. Процесс будет иметь приоритет выше нормального.

HIGH_PRIORITY_CLASS (128): Высокий приоритет процесса. Процесс будет выполняться с более высоким приоритетом и получать больше процессорного времени.

REALTIME_PRIORITY_CLASS (256): Приоритет реального времени. Процесс будет иметь максимальный приоритет и будет получать процессорное время без учета других процессов. Используйте это значение с осторожностью, так как оно может повлиять на производительность системы и привести к блокировкам.

UNKNOWN (0): Значение по умолчанию, если класс приоритета не определен.

*/