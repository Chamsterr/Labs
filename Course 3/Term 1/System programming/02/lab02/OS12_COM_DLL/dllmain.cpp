#include "pch.h"
#include <fstream>
#include "ICom.h"
#define SEQ LONG __XXCSeq=InterlockedIncrement(&Seq)
#define LOG(x,y) LogCOM<<__XXCSeq<<":"<<x<<y<<std::endl

HMODULE hmodule;    //для хранения дескриптора (указателя) на модуль DLL.
LONG Seq = 0;
std::fstream LogCOM;

ULONG g_Components = 0;
ULONG g_ServerLocks = 0;

BOOL APIENTRY DllMain( HMODULE hModule, //Дескриптор (указатель) на модуль DLL.
                       DWORD  ul_reason_for_call,   //тот параметр указывает, по какому поводу была вызвана функция DllMain
                       LPVOID lpReserved    //Зарезервирован для использования
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:    //когда DLL подключается к процессу
        hmodule = hModule;
        LogCOM.open("D:\Labs\Course 3\Term 1\System programming\02\lab02OS12logCom.txt", std::ios_base::out);    //открывается файл для записи журнала
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:    //когда DLL отключается от процесса
        LogCOM.close(); // Закрывается файл журнала
        break;
    }
    return TRUE;
}

