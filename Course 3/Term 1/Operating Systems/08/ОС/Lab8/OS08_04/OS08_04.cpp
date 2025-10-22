#include <windows.h>
#include <iostream>

//14. Разработайте консольное приложение OS06_04,
//которое включает функцию sh, принимающую 1 параметр: дескриптор (HANDLE) heap.

void sh(HANDLE heap) {
    SetConsoleOutputCP(1251);
    PROCESS_HEAP_ENTRY entry;
    entry.lpData = NULL;
    SIZE_T totalSize = 0, allocatedSize = 0, unallocatedSize = 0;

    while (HeapWalk(heap, &entry) != FALSE) {
        totalSize += entry.cbData;
        if (entry.wFlags & PROCESS_HEAP_ENTRY_BUSY) {
            allocatedSize += entry.cbData;
        }
        else {
            unallocatedSize += entry.cbData;
        }
    }
    //15. Функция sh выводит на консоль, общий размер heap,
    //размеры распределенной  и нераспределенных  областей памяти heap.
    std::cout << "Общий размер heap: " << totalSize << "\n";
    std::cout << "Размер распределенной области памяти heap: " << allocatedSize << "\n";
    std::cout << "Размер нераспределенной области памяти heap: " << unallocatedSize << "\n";
}

int main() {
    HANDLE heap = GetProcessHeap();
    sh(heap);

    //16. Приложение OS06_04 размещает в стандартной heap процесса int-массив размерности 300000.   
    const int ARRAYSIZE = 300000;
    int* array = new int[ARRAYSIZE];

    //17. Выведите с помощью функции sh информацию до размещения массива и после. 
    sh(heap);

    delete[] array;
    return 0;
}
