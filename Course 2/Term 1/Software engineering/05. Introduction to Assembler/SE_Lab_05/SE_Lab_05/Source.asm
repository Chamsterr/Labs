.586
.model flat, stdcall
includelib libucrt.lib
includelib kernel32.lib
ExitProcess PROTO:DWORD 
.stack 4096

 PrintNumber PROTO : DWORD

 PrintString PROTO : DWORD

 PrintStrLine PROTO : DWORD

 PrintNumLine PROTO : DWORD

 SystemPause PROTO 

 lenght PROTO: DWORD, : DWORD

 Power PROTO : DWORD, : DWORD

 convert PROTO: DWORD, : DWORD

 EXTRN substr: PROC;
 substr PROTO: DWORD, : DWORD, : DWORD

.const
 null_division BYTE 'ERROR: DIVISION BY ZERO', 0
 overflow BYTE 'ERROR: VARIABLE OVERFLOW', 0 
	L1 BYTE '12', 0
	L2 SDWORD 0
	L3 SDWORD 1
	L4 BYTE '11', 0
.data
  buffer byte 256 dup(0) 
	mainstr1 DWORD ?
	mainstr2 DWORD ?
	mainanswer SDWORD 0
	mainres SDWORD 0

.code

main PROC
	push offset L1
	pop mainstr1

	push offset substr
	push L2
	push L3
	push offset L4
	pop edx
	pop edx
	pop edx
	pop edx

	push offset L4
	push L3
	push L2
 
		call substr
	push eax
	pop mainstr2


push mainstr2
call PrintStrLine


	push convert
	push mainstr1

	pop edx
	pop edx
	push mainstr1
	push offset buffer
 
		call convert
	push eax
	pop mainanswer

	push lenght
	push mainstr1
	pop edx
	pop edx
	push mainstr1
	push offset buffer
 
		call lenght
	push eax
	pop mainres


push mainres
call PrintNumLine

push mainanswer
call PrintNumLine
call SystemPause
push 0
call ExitProcess
SOMETHINGWRONG:
push offset null_division
call PrintStrLine
call SystemPause
push -1
call ExitProcess
EXIT_OVERFLOW:
push offset overflow
call PrintStrLine
call SystemPause
push -2
call ExitProcess
main ENDP
end main