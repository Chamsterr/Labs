.586

.MODEL FLAT, STDCALL

includelib kernel32.lib
includelib libucrt.lib
includelib ..\\Debug\\SE_Lab_05d.lib

EXTRN getminC: proc
EXTRN getmaxC: proc

ExitProcess PROTO : DWORD

.STACK 4096

.DATA
myDoubles DWORD 7, 2, 3, 4, -1, 6, 5
myPointer DWORD myDoubles
minimum DWORD ?
maximum DWORD ?

.CODE
main PROC
START :

push lengthof myDoubles
push myPointer
call getminC

push lengthof myDoubles
push myPointer
call getmaxC

INVOKE ExitProcess, 0
main ENDP

end main