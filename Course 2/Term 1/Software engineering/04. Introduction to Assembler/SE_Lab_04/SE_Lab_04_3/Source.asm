.586P 
.MODEL FLAT, STDCALL 
includelib kernel32.lib 
ExitProcess PROTO : DWORD 
.STACK 586 
.DATA 
   char_ BYTE "N", 0
   literal BYTE "P", 0
.CODE 
main PROC 
START: 
    invoke ExitProcess, 0
    
main ENDP 
end main