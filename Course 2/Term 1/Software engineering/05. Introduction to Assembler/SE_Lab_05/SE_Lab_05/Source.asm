.586P												
.MODEL FLAT, STDCALL									
includelib kernel32.lib									

getmin PROTO :DWORD, :DWORD
getmax PROTO :DWORD, :DWORD

ExitProcess PROTO :DWORD							

.STACK 586									

.CONST													

.DATA
	myDoubles DWORD 7, 2, 3, 4, -1, 6, 5
	myPointer DWORD myDoubles
	minimum DWORD ?
	maximum DWORD ?



.CODE			
getmax PROC myPointer1 : DWORD, lenght1 : DWORD 
	START:
		mov ECX, lenght1
		sub ECX, 1
		mov ESI, myPointer1

		mov EAX, [ESI]

		CYCLE:
			mov EBX, [ESI + 4]

			add ESI, type myPointer1
			cmp EBX, EAX

			jg mhw
			BACK:
				loop CYCLE

			ret
		mhw:
			mov EAX, EBX
			jmp BACK

	getmax ENDP

	getmin PROC myPointer1 : DWORD, lenght1 : DWORD 
	START:
		mov ECX, lenght1
		sub ECX, 1
		mov ESI, myPointer1

		mov EAX, [ESI]

		CYCLE:
			mov EBX, [ESI + 4]

			add ESI, type myPointer1
			cmp EBX, EAX

			jl mhw
			BACK:
				loop CYCLE

			ret
		mhw:
			mov EAX, EBX
			jmp BACK

	getmin ENDP
main PROC												
START :

	INVOKE getmin, myPointer, lengthof myDoubles
	mov minimum, EAX
	
	INVOKE getmax, myPointer, lengthof myDoubles
	mov maximum, EAX

	INVOKE ExitProcess, 0
main ENDP

end main