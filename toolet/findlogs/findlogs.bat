::v0.1@20160309
::v0.2@20160314

@echo off
:: configs
set bak_root=f:\bak

set input=key.in
set name=name.tmp
set list=list.tmp
set output=loglist.out
set logfile=run.log


del %name%
del %list%
del %logfile%

:: 对输入文件进行处理获搜索目标

FOR /f "delims=" %%i in (%input%) do (
    echo %%~ni>>%name%
)

:: 拼接命令行参数
set flag=0
FOR /f "delims=" %%i in (%name%) do (
    call :concat_key "%%i"
)

echo keys=%keys%>>%logfile%

echo **** start finding logs...
find %* %keys% > %list%
echo **** finish finding.



::对搜索结果进行过滤
FOR /F "delims=" %%i in (%input%) do (
    call :concat_pattern "%%i"
)
echo patterns=%patterns%>>%logfile%
grep %patterns% %list% >%output%

set count=0
echo **** start copy logs...
FOR /f "delims=" %%i in (%output%) do (
    call :mk2cp "%%i"
)

echo **** finished copy.
:: unset variables
set bak_root=
set input=
set output=
set list=
set name=
set logfile=

set keys=
set patterns=

set flag=
set last=
set trans=
set dest=


goto :eof

:concat_key
if %flag%==0 (
set keys=%keys% -iname %1
set flag=1
) else (
set keys=%keys% -o -iname %1
)
goto :eof


:concat_pattern
set patterns=%patterns% -e %1
goto :eof


:mk2cp
set /A count+=1
set dest=%bak_root%\%count%
mkdir "%dest%"
xcopy %1 "%dest%" /e /y >nul
goto :eof

