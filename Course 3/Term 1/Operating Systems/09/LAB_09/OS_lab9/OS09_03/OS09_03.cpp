#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <vector>
#include <string>

BOOL insRowFileTxt(LPWSTR FileName, LPWSTR str, DWORD row) {
    FILE* file = _wfopen(FileName, L"r");
    if (file == NULL) {
        wprintf(L"Could not open file %s\n", FileName);
        return FALSE;
    }

    std::vector<std::wstring> lines;
    wchar_t line[256];
    while (fgetws(line, sizeof(line) / sizeof(wchar_t), file)) {
        lines.push_back(line);
    }
    fclose(file);

    file = _wfopen(FileName, L"w");
    if (file == NULL) {
        wprintf(L"Could not open file %s\n", FileName);
        return FALSE;
    }

    if (row == (DWORD)-1) {
        row = lines.size();
    }

    for (DWORD i = 0; i <= lines.size(); i++) {
        if (i == row) {
            fputws(str, file);
            fputws(L"\n", file);
        }
        if (i < lines.size()) {
            fputws(lines[i].c_str(), file);
        }
    }

    fclose(file);

    return TRUE;
}


int main() {

    SetConsoleOutputCP(65001);//UTF-8

    wchar_t temp[] = L"OS09_01.txt";
    LPWSTR FileName = new wchar_t[wcslen(temp) + 1];
    wcscpy(FileName, temp);

    wchar_t temp2[] = L"OS09_01.txt";
    LPWSTR str = new wchar_t[wcslen(temp) + 1];
    wcscpy(str, temp2);

    DWORD rowsToInsert[] = { 0, (DWORD)-1, 5, 7 };
    for (int i = 0; i < sizeof(rowsToInsert) / sizeof(DWORD); i++) {
        if (!insRowFileTxt(FileName, str, rowsToInsert[i])) {
            printf("Exception when insert %d\n", rowsToInsert[i]);
        }
    }
    return 0;
}
