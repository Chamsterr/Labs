@echo off
echo ��ப� ��ࠬ��஢: %*
echo �����: %1
echo ��� 䠩��: %2

if "%1"=="" if "%2"=="" (
    echo ERROR: �� 㪠��� ०��. �������� ०���: 㤠����, ᮧ����
    exit /b 1
)

if "%1" neq "㤠����" if "%1" neq "ᮧ����" (
    echo ERROR: ����୮ ����� ०��
    exit /b 1
)

if "%2"=="" (
    echo ERROR: �� 㪠���� ��� 䠩��
    exit /b 1
)

if "%1"=="ᮧ����" (
    if exist %2 (
        echo ERROR: 䠩� 㦥 ᮧ���
        exit /b 1
    ) 
    echo ���� ᮧ��� %2 
    echo. > %2
    exit /b 1
)

if "%1"=="㤠����" (
    if exist %2 (
        del %2
        echo 䠩�� %2 㤠���
        exit /b 1
    ) else (
        echo ERROR: 䠩�� "%2" �� �������
    )
)
