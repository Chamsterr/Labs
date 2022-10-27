.586P												
.MODEL FLAT, STDCALL									

.STACK 586									

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
end