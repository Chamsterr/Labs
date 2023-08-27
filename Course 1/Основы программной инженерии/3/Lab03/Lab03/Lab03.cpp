#include <iostream>
//1)KovkelNikita2004
// windows-1251: 4b 6f 76 6b 6c 4e 69 6b 69 74 61 32 30 30 34
// UTF-8: 004b 006f 0076 006b 0065 006c 004e 0069 006b 0069 0074 0061 0032 0030 0030 0034
// UTF-16: 004B 006f 0076 006b 0065 006C 004E 0069 006B 0069 0074 0061 0032 0030 0030 0034

//2)КовкельНикитаВикторович2004
// windows-1251: ca ee e2 ea e5 eb fc cd e8 ea e8 f2 e0 c2 e8 ea f2 ee f0 ee e2 e8 f7 32 30 30 34
//UTF-8: 041a 043e 0432 043a 0435 043b 044c 041d 0438 043a 0438 0442 0430 0412 0438 043a 0442 043e 0440 043e 0432 0438 0447 0032 0030 0030 0034
//UTF - 16: 041a 043e 0432 043a 0435 043b 044c 041d 0438 043a 0438 0442 0430 0032 0030 0030 0034
//3)Ковкель2004Nikita
// windows-1251: ca ee e2 ea e5 eb fc 32 30 30 34 4e 69 6b 69 74 61 00
//UTF-8: 041a 043e 0432 043a 0435 043b 044c 0032 0030 0030 0034 004e 0069 006b 0069 0074 0061
//UTF - 16: 1a04 3e04 3204 3a04 3504 3b04 4c04 0032 0030 0030 0034 004e 0069 006b 0069 0074 0061
int main()
{
    int number = 0x12345678;
    char hello[] = "Hello, ";
    char lfie[] = "KovkelNikita2004";
    char rfie[] = "КовкельНикитаВикторович2004";
    char lr[] = "Ковкель2004Nikita";

    wchar_t Lfie[] = L"KovkelNikita2004";
    wchar_t Rfie[] = L"КовкельНикита2004";
    wchar_t LR[] = L"Ковкель2004Nikita";

    std::cout << hello << lfie << std::endl;
    return 0;
}