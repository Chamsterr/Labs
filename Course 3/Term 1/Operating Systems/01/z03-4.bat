@echo off

set /a number1 = %1 + %2
set /a number2 = %1 * %2
set /a number3 = %3 / %2
set /a number4 = %2 - %1
set /a number5 = number4 * (%1 - %2)

echo -- параметр 1: %1
echo -- параметр 2: %2
echo -- параметр 3: %3

echo %number1%
echo %number2%
echo %number3%
echo %number4%