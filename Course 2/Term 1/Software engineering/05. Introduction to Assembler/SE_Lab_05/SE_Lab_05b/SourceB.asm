.586

.MODEL FLAT, STDCALL

includelib kernel32.lib
includelib "..\Debug\SE_Lab_05lib.lib"


getmin PROTO : DWORD, : DWORD
getmax PROTO : DWORD, : DWORD

ExitProcess PROTO : DWORD

.STACK 4096

.DATA
myDoubles DWORD 7, 2, 3, 4, -1, 6, 5
myPointer DWORD myDoubles
minimum DWORD ?
maximum DWORD ?

word1 DWORD ?

.CODE
main PROC
START :

INVOKE getmin, myPointer, lengthof myDoubles
mov minimum, EAX

INVOKE getmax, myPointer, lengthof myDoubles
mov maximum, EAX


INVOKE ExitProcess, 0
main ENDP

end main