#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>

BOOL printFileInfo(LPWSTR FileName) {
    WIN32_FIND_DATA FindFileData;
    HANDLE hFind;

    hFind = FindFirstFile(FileName, &FindFileData);
    if (hFind == INVALID_HANDLE_VALUE) {
        printf("FindFirstFile failed (%d)\n", GetLastError());
        return FALSE;
    }
    else {
        // Имя файла
        wprintf(L"FileName: %s\n", FindFileData.cFileName);

        // Расширение файла
        LPWSTR ext = wcsrchr(FindFileData.cFileName, L'.');
        if (ext != NULL)
            wprintf(L"File extension: %s\n", ext);
        else
            wprintf(L"No file extension\n");

        // Размер файла
        LARGE_INTEGER size;
        size.HighPart = FindFileData.nFileSizeHigh;
        size.LowPart = FindFileData.nFileSizeLow;
        printf("File size: %lld byte\n", size.QuadPart);

        // Дата и время создания файла
        FILETIME ftCreate = FindFileData.ftCreationTime;
        SYSTEMTIME stUTC, stLocal;
        FileTimeToSystemTime(&ftCreate, &stUTC);
        SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
        printf("Create date and time: %02d/%02d/%d  %02d:%02d\n",
            stLocal.wDay, stLocal.wMonth, stLocal.wYear,
            stLocal.wHour, stLocal.wMinute);

        // Дата и время последнего обновления
        FILETIME ftWrite = FindFileData.ftLastWriteTime;
        FileTimeToSystemTime(&ftWrite, &stUTC);
        SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
        printf("Last update date and time: %02d/%02d/%d  %02d:%02d\n",
            stLocal.wDay, stLocal.wMonth, stLocal.wYear,
            stLocal.wHour, stLocal.wMinute);

        FindClose(hFind);
    }
    return TRUE;
}

BOOL printFileTxt(LPWSTR FileName) {

    FILE* file = _wfopen(FileName, L"r");
    if (file == NULL) {
        wprintf(L"Could not open file %s\n", FileName);
        return FALSE;
    }

    wchar_t ch;
    while ((ch = fgetwc(file)) != WEOF)
        putwchar(ch);

    fclose(file);
    return TRUE;
}

#include <string.h>

int main() {
    SetConsoleOutputCP(65001);

    wchar_t temp[] = L"OS09_01.txt";

    LPWSTR FileName = new wchar_t[wcslen(temp) + 1];
    wcscpy(FileName, temp);

    if (!printFileInfo(FileName)) {
        printf("Ошибка при выводе информации о файле\n");
    }
    if (!printFileTxt(FileName)) {
        printf("Ошибка при выводе содержимого файла\n");
    }
    delete[] FileName;

    return 0;
}

