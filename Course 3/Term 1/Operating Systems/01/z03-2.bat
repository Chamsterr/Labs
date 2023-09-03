@echo off
REM 866
echo --имя этого бат-файла: %~nx0

for %%A in ("%~dp0.") do set "creation_date=%%~tA"
echo --этот бат-файл создан: %creation_date%


echo --путь бат-файла: %~dp0