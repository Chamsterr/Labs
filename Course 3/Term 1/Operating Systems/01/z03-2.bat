@echo off
REM 866
echo --��� �⮣� ���-䠩��: %~nx0

for %%A in ("%~dp0.") do set "creation_date=%%~tA"
echo --��� ���-䠩� ᮧ���: %creation_date%


echo --���� ���-䠩��: %~dp0