@echo off
cls
echo -- ��� �⮣� bat-䠩��: %~n0
for /f "skip=5 tokens=1-2" %%a in ('dir %~n0.bat /T:C') do echo -- ��� bat-䠩� ᮧ���: %%a %%b & goto :STOP
:STOP
echo -- ���� bat-䠩��: %~0
pause