// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"


HMODULE g_hModule;
const wchar_t* g_szFriendlyName = L"OS13.ComponentHT.COM";
const wchar_t* g_szVerIndProgID = L"OS13.ComponentHT.1";
const wchar_t* g_szProgID = L"OS13.ComponentHT";              
long g_cComponents = 0;		                               
long g_cServerLocks = 0;                                    


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

