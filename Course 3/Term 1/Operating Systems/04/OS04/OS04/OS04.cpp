#include <iostream>
#include <Windows.h>

using namespace std;

// 1. Powershell ISE:		(Get-Process OS04).Threads

int main()
{
	DWORD pid = GetCurrentProcessId();
	DWORD tid = GetCurrentThreadId();

	for (short i = 1; i <= 10000; ++i)
	{
		cout << i << ". PID = " << pid << "\t\tTID = " << tid << "\n";
		Sleep(1000);
	}

	system("pause");
	return 0;
}