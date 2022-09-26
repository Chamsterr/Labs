.586P													
.MODEL FLAT, STDCALL									
includelib kernel32.lib									

ExitProcess PROTO :DWORD								

.STACK 586									

.CONST													

.DATA
	str0 DB "03Asm", 0
	myBytes BYTE 10h, 20h, 30h, 40h
	myWords WORD 2Ah, 3Bh, 44h, 5Fh, 99h
	myDoubles DWORD 1, 2, 3, 4, 5, 6
	myPointer DWORD myDoubles

	arr DWORD 1, 0, 2, 3, 4, 5, 6
	sum DWORD 0	
.CODE													

main PROC												
START :													
	mov ESI, OFFSET myWords
	mov AX, [ESI + 0]
	mov BX, [ESI + 2] 
	
	mov ESI, OFFSET myDoubles
	mov AX, [ESI + 0]
	mov AX, [ESI + 8]
	
	mov ECX, lengthof arr

	mov ESI, OFFSET arr


	mov EBX, 1
	CYCLE:
		mov EAX, [ESI]

		add sum, EAX 
		add ESI, type arr

		cmp EAX, 0
		jz ifZero
		BACK:
			loop CYCLE
	
	invoke ExitProcess, 0

	ifZero:
		mov EBX, 0
		jmp BACK

main ENDP

end main