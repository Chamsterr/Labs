#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <string>

DWORD countLines(LPWSTR FileName) {
    FILE* file = _wfopen(FileName, L"r");
    if (file == NULL) {
        wprintf(L"Could not open file %s\n", FileName);
        return 0;
    }

    DWORD count = 0;
    wchar_t ch;
    while ((ch = fgetwc(file)) != WEOF) {
        if (ch == L'\n') {
            count++;
        }
    }
    fclose(file);

    return count;
}

BOOL printWatchRowFileTxt(LPWSTR FileName, DWORD mlsec) {
    DWORD prevCount = countLines(FileName);
    wprintf(L"Initial line count: %d\n", prevCount);

    HANDLE hDir = CreateFileW(
        L".", GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
        NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
    if (hDir == INVALID_HANDLE_VALUE) {
        wprintf(L"Could not open directory\n");
        return FALSE;
    }

    char buffer[1024];
    DWORD bytesReturned;
    while (ReadDirectoryChangesW(hDir, buffer, sizeof(buffer), TRUE,
        FILE_NOTIFY_CHANGE_SIZE | FILE_NOTIFY_CHANGE_LAST_WRITE, &bytesReturned, NULL, NULL)) {
        Sleep(mlsec);
        DWORD newCount = countLines(FileName);
        if (newCount != prevCount) {
            wprintf(L"Line count changed: %d -> %d\n", prevCount, newCount);
            prevCount = newCount;
        }
    }

    CloseHandle(hDir);
    return TRUE;
}

int main() {
    SetConsoleOutputCP(65001);//UTF-8

    wchar_t temp[] = L"OS09_01.txt";
    LPWSTR FileName = new wchar_t[wcslen(temp) + 1];
    wcscpy(FileName, temp);
    if (!printWatchRowFileTxt(FileName, 1000)) {
        wprintf(L"Ошибка при отслеживании изменений в файле\n");
        return 1;
    }
    return 0;
}
