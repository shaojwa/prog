@echo off

if ["%1"] == [""] (
    echo usage: %~n0 backup_root
    goto :eof
)
set batpath=%~dp0
set backup_root=%1
set count=0
set input=%batpath%list.out

echo %input%

if not EXIST "%input%" (
    goto :eof
)


rem get time which is used in naming folder
for /f "tokens=1-3 delims=/ " %%i in ("%date%") do (
    set year=%%i
    set month=%%j
    set day=%%k
)
set timestr=%year%-%month%-%day%
for /f "tokens=1-3 delims=:. " %%i in ("%time%") do (
    set hh=%%i
    set mm=%%j
    set ss=%%k
)

set timestr=%timestr%-%hh%%mm%%ss%
echo %timestr%

FOR /f "delims=" %%i in (%input%) do (
    call :mk2cp "%%i"
)

set backup_root=
set count=
set input=
set timestr=
set dest=
goto :eof


:mk2cp
set /A count+=1
set dest=%backup_root%\%timestr%\%count%
echo %dest%
mkdir "%dest%"
xcopy %1 "%dest%" /e /y >nul
goto :eof
