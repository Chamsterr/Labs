	.586													;������� ������(��������� Pentium)

	.MODEL FLAT, STDCALL									;������ ������, ���������� � �������

	includelib kernel32.lib									; ������������: ����������� � kernel32.lib

	ExitProcess PROTO : DWORD								; �������� ������� ExitProcess
	MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD	; �������� ������� MessageBox

	.STACK 4096												; c������ ����� ������� 4096
																																
	.CONST													; ������� ��������

	.DATA													; ������� ������ 
	MB_OK		EQU 1										; EQU ���������� ��������� 
	STR1		DB "��� ������ ���������", 0				; ������ + ������� ����
	STR2		DB "������ ����!", 0						; ������ + ������� ����
	HW			DD ?										; ������� ����� ������� 4 �����, ������������������

	.CODE													; ������� ����

	main PROC												; ����� �����, ������ ��������� main
	START :													; �����
	
		INVOKE  MessageBoxA, HW, OFFSET STR2, OFFSET STR1, MB_OK			
	;		PUSH	MB_OK									
	;		PUSH	OFFSET STR1								
	;		PUSH	OFFSET STR2								
	;		PUSH	HW										
	;		CALL	MessageBoxA								; ����� �������

		push -1												; ��� �������� �������� Windows(�������� ExitProcess)
		call ExitProcess									; ��� ����������� ����� ������� Windows
	main ENDP												; ����� ���������

	end main												; ����� ������ main		