::20160317
@echo off
echo %cmdcmdline%
echo %*
echo %0
echo %1
echo %2
echo %3
echo %4
echo %5
echo %6
echo %7
echo %8
echo %9

set arg=par
set par=looks

if defined arg ( echo deinfed ) else ( echo not-defined)

if [%arg%]==[] ( echo name-empty) else ( echo arg=%arg%)

call:change %arg%
echo %arg%
echo %par%
goto :eof


:change
set %1=world
goto :eof
