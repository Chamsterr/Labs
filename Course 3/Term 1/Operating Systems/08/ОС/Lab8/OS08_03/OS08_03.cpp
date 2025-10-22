#include <iostream>
#include <Windows.h>

using namespace std;

#define KB (1024)
#define MB (1024 * KB)
#define PG (4 * KB)


void saymem()
{
    MEMORYSTATUS ms;
    GlobalMemoryStatus(&ms);
    cout << "Объём физической памяти:      " << ms.dwTotalPhys / KB << " KB\n";
    cout << "Доступно физической памяти:   " << ms.dwAvailPhys / KB << " KB\n";
    cout << "Объем виртуальной памяти:     " << ms.dwTotalVirtual / KB << " KB\n";
    cout << "Доступно виртуальной памяти:  " << ms.dwAvailVirtual / KB << " KB\n\n";
}

//Запишите 3 первых буквы своей фамилии в 16-ричными числами в кодировке Windows-1251.
/*
"П" = 207 = 0xCF
"е" = 229 = 0xE5
"с" = 241 = 0xF1

 Страница CF = 207

    207 * 4096 = 847872(10) = 0xCF000 - добавить для перехода на страницу
                 
    E5F = 3679

    Искомое значение: начало массива + 0xCF000 + 0xE5F
    

    //ИРА

"В" = 194 = 0xC2
"и" = 232 = 0xE8
"к" = 234 = 0xEA

    Страница C2 = 194

    194 * 4096 = 794624(10) =  0xC2000  - добавить для перехода на страницу
    
    из 16 в 10

    E8E = 3726
    Искомое значение: начало массива + 0xC2000 + 0xE8E

      //Ковкель

      К = 202 = 0xCA
      o = 238 = 0xEE
      в = 226 = 0xE2

    Страница CA = 202

    202 * 4096 = 827392(10) =  0xCA000  - добавить для перехода на страницу

    из 16 в 10
    EEE = 3822

    Искомое значение: начало массива + 0xCA000 + 0xEEE
*/


int main()
{
    setlocale(LC_ALL, "ru");
    //9. Разработайте консольное приложение OS06_03, выполняющее получение 256 страниц оперативной памяти.
    int pages = 256;
    int countItems = pages * PG / sizeof(int);
    SYSTEM_INFO system_info;
    GetSystemInfo(&system_info);

    cout << "\t    Изначально в системе\n";
    saymem();

    // выделено 1024 KB виртуальной памяти
    LPVOID xmemaddr = VirtualAlloc(NULL, pages * PG, MEM_COMMIT, PAGE_READWRITE);
	
    cout << "\tВыделено " << pages * PG / 1024 << " KB вирт. памяти\n";
    saymem();

    int* arr = (int*)xmemaddr;
    for (int i = 0; i < countItems; i++)
        arr[i] = i;

    int* byte = arr + 202 * 1024 + 3822;
    cout << "------  Значение памяти в байте: " << *byte << "  ------\n";

    VirtualFree(xmemaddr, NULL, MEM_RELEASE) ? 
        cout << "\tВиртуальная память освобождена\n"
			:
		cout << "\tВиртуальная память не освобождена\n";
    saymem();
}