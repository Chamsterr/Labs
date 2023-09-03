@echo off
echo Первый параметр: %1
echo Второй параметр: %2
echo Третий параметр: %3

set /a result1=%1 %3 %2


echo Результат: %result1%