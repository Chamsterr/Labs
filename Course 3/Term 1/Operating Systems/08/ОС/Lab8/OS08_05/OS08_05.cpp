#include <windows.h>
#include <iostream>
//14. Разработайте консольное приложение OS06_04,
//которое включает функцию sh, принимающую 1 параметр: дескриптор (HANDLE) heap.

void sh(HANDLE heap) {
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

// Параметры пользовательской кучи:
    // 1. доступ не синхронизирован
    // 2. куча заполняется нулями
    // 3. начальный размер 4 мб
    // 4. конечный размер ограничен размером виртуальной памяти

int main() {
    SetConsoleOutputCP(1251);
    //19. Разработайте консольное приложение OS06_05 аналогичное приложению OS06_05,
    //но использующее пользовательскую heap, которая имеет первоначальный размер 4MB.    
    const SIZE_T HEAPSIZE = 4 * 1024 * 1024;
    HANDLE heap = HeapCreate(0, HEAPSIZE, 0);
    sh(heap);
    //16. Приложение OS06_04 размещает в стандартной heap процесса int-массив размерности 300000.   

    const int ARRAYSIZE = 300000;
    int* array = (int*)HeapAlloc(heap, 0, ARRAYSIZE * sizeof(int));
    //17. Выведите с помощью функции sh информацию до размещения массива и после.
    sh(heap);

    HeapFree(heap, 0, array);
    HeapDestroy(heap);

    return 0;
}


/*
4-5 кучи и адресап куда
входит адрес в какую область памяти?
*/

