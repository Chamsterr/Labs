@echo off
echo Строка параметров: %*
echo Режим: %1
echo Имя файла: %2

if "%1"=="" if "%2"=="" (
    echo ERROR: не указан режим. возможные режимы: удалить, создать
    exit /b 1
)

if "%1" neq "удалить" if "%1" neq "создать" (
    echo ERROR: неверно задан режим
    exit /b 1
)

if "%2"=="" (
    echo ERROR: не указано имя файла
    exit /b 1
)

if "%1"=="создать" (
    if exist %2 (
        echo ERROR: файл уже создан
        exit /b 1
    ) 
    echo Файл создан %2 
    echo. > %2
    exit /b 1
)

if "%1"=="удалить" (
    if exist %2 (
        del %2
        echo файла %2 удален
        exit /b 1
    ) else (
        echo ERROR: файла "%2" не существует
    )
)
