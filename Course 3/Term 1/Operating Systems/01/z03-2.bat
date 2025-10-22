@echo off
cls
echo -- имя этого bat-файла: %~n0
for /f "skip=5 tokens=1-2" %%a in ('dir %~n0.bat /T:C') do echo -- этот bat-файл создан: %%a %%b & goto :STOP
:STOP
echo -- путь bat-файла: %~0
pause