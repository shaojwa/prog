@echo off

if ["%2"] == [""] (
    echo usage: %~0 search_path pattern
    goto :eof
)


set batpath=%~dp0
set search_path=%1
set pattern=%2
set outfile=%batpath%list.out

if exist "%outfile%" (
    del /f /q "%outfile%"
)

cd /d %search_path%
dir %pattern% /B /S > %outfile%

set batpath=
set search_path=
set pattern=
set outfile=
goto :eof
