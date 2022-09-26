	.586													;система команд(процессор Pentium)

	.MODEL FLAT, STDCALL									;модель памяти, соглашение о вызовах

	includelib kernel32.lib									; компановщику: компановать с kernel32.lib

	ExitProcess PROTO : DWORD								; прототип функции ExitProcess
	MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD	; прототип функции MessageBox

	.STACK 4096												; cегмент стека объемом 4096
																																
	.CONST													; сегмент констант

	.DATA													; сегмент данных 
	MB_OK		EQU 1										; EQU определяет константу 
	STR1		DB "Моя первая программа", 0				; строка + нулевой байт
	STR2		DB "Привет всем!", 0						; строка + нулевой байт
	HW			DD ?										; двойное слово длинной 4 байта, неинициализирована

	.CODE													; сегмент кода

	main PROC												; точка входа, начало процедуры main
	START :													; метка
	
		INVOKE  MessageBoxA, HW, OFFSET STR2, OFFSET STR1, MB_OK			
	;		PUSH	MB_OK									
	;		PUSH	OFFSET STR1								
	;		PUSH	OFFSET STR2								
	;		PUSH	HW										
	;		CALL	MessageBoxA								; вызов функции

		push -1												; код возврата процесса Windows(параметр ExitProcess)
		call ExitProcess									; так завершается любой процесс Windows
	main ENDP												; конец процедуры

	end main												; конец модуля main		