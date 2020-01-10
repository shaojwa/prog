::
::by pwns
::224020151112
::
@echo off
FOR  /f "tokens=1" %%i in ('net view') DO call :get_host %%i
goto end

:get_host
set host=%1
if /i "%host:~0,2%"=="\\" (
    set pc=%host:~2%
    @echo %pc%
    for /f %%j in ('ping %pc% -4 -n 1') DO (
        call :get_ip %%j
    )
)
goto :eof

:get_ip
set word=%1
::@echo %word%
if /i "%word:~0,1%"=="1" @echo %word%
goto :eof

:end
