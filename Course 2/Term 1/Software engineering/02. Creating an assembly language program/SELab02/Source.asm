.586P													
.MODEL FLAT, STDCALL									
includelib kernel32.lib									

ExitProcess PROTO :DWORD								
MessageBoxA PROTO :DWORD, :DWORD, :DWORD, :DWORD

.STACK 586									

.CONST													

.DATA				
		a dd 4	
		b dd 2
		str0 db "02ASM", 0 
		str1 db "Результат сложения = < >", 0 

.CODE													

main PROC												
START :													
		mov eax, a									   
		add eax, b										
		add eax, 30h 								    
		
		mov str1+22, al									
		
		invoke MessageBoxA, 0, offset str1, offset str0, 0
		invoke ExitProcess, 0

main ENDP

end main