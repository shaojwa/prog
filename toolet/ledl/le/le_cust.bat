::v0.1@20160309
::v0.2@20160314
::v0.2@20160908

@echo off
:: configs

set pattern=%1
set search_root=%2
set backup_root=%3

set findfile=find.out
set grepfile=grep.out
set logfile=run.log


if exist "%findfile%" (
    del %findfile%
)

if exist "%grepfile%" (
    del %grepfile%
)

if exist "%logfile%" (
    del %logfile%
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

echo **** start finding...
echo find %search_root% -iname %pattern%
find %search_root% -iname %pattern% > %findfile%
echo **** finding log finished.


set count=0
echo **** start backup ...
FOR /f "delims=" %%i in (%findfile%) do (
    call :mk2cp "%%i"
)
echo **** backup finished.


:: unset variables
set search_root=
set backup_root=
set keyfile=
set listfile=
set logfile=
set keys=
set patterns=
set timestr=
set flag=
set dest=
goto :eof


:mk2cp
set /A count+=1
set dest=%backup_root%\%timestr%\%count%\
mkdir "%dest%"
echo %1 %dest%
xcopy %1 %dest% /e /y >nul
goto :eof

