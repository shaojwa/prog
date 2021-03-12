
@echo off
set input=key.in
set output=loglist.out

set flag=0
FOR /f %%i in (%input%) do (
   call :concat %%i
)

find %* %keys% > %output%

:: unset variables
set input=
set output=
set keys=

goto :eof

:concat
if %flag%==0  (
set keys=%keys% -iname %1
set flag=1
) else (
set keys=%keys% -o -iname %1
)
goto :eof
