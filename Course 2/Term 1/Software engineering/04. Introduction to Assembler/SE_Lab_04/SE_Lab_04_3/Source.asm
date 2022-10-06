.586
.MODEL FLAT, STDCALL
INCLUDELIB kernel32.lib
ExitProcess PROTO : DWORD 
.STACK 1024
.CONST
   literal1 BYTE "N", 0
   literal2 BYTE "N", 0

.DATA
   char1 BYTE "N", 0
   char2 BYTE "N", 0

.CODE 
main PROC 
START: 
    INVOKE ExitProcess, 0
main ENDP 
end main