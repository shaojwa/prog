@rem 20160524
@echo off

if [%2] == [] (
    echo ERROR: arguments is not enough
    echo Usage: %~0 image outdir
    goto :eof
)

if NOT EXIST "%1" (
    echo ERROR: no such image file: %1
    goto :eof
)

if NOT EXIST "%2" (
    echo ERROR: no such directory: %2
    goto :eof
)

set huntdir=%~dp0
set image=%1
set outdir=%2
set sleuthkit=D:\sleuthkit-4.2.0-win32\bin
set config=%huntdir%\hunt.conf
set logfile=%huntdir%\hunt.log
set tmpdir=%huntdir%\tmp
set flsfile=%tmpdir%\fls.tmp
set grpfile=%tmpdir%\grp.tmp
set awkfile=%tmpdir%\awk.tmp
set idsfile=%tmpdir%\ids.tmp

echo begin at %date% %time% >> %logfile%

if NOT exist "%config%" (
    echo ERROR: no config file
    goto :eof
)

%sleuthkit%\fls -r %image% > %flsfile%
set errorcode=%errorlevel%
if %errorcode% NEQ 0 (
    echo ERROR: get error when running sleuthkit
    goto :eof
)

set patterns=
FOR /F "delims=" %%i in (%config%) do (
    call :concat_pattern "%%i"
)

echo patterns=%patterns% >> %logfile%
%huntdir%\grep -w %patterns%  %flsfile% > %grpfile%
set errorcode=%errorlevel%
if %errorcode% NEQ 0 (
    echo ERROR: grep failed, code=%errorcode%
    goto :eof
)

echo grep file done >> %logfile%

%huntdir%\awk -F '[ :]' '{if($1 ~/+/) print $3,$4; else print $2,$3}' %grpfile% > %awkfile%
set errorcode=%errorlevel%
if %errorcode% NEQ 0 (
    echo ERROR: awk failed in phase 1, code=%errorcode%
    goto :eof
)

%huntdir%\awk '$1!="*" {print $1,$2}' %awkfile% > %idsfile%
set errorcode=%errorlevel%
if %errorcode% NEQ 0 (
    echo ERROR: awk failed in phase 2, code=%errorcode%
    goto :eof
)

echo awk file done >> %logfile%

FOR /f "tokens=1-2 delims= " %%i in (%idsfile%) do (
    %sleuthkit%\icat %image% %%i > %outdir%\%%i_%%j
)
echo icat file done >> %logfile%
echo ended at %date% %time% >> %logfile%

set huntdir=
set image=
set outdir=
set sleuthkit=
set config=
set logfile=
set tmpdir=
set flsfile=
set grpfile=
set awkfile=
set idsfile=
set patterns=

goto :eof

:concat_pattern
set patterns=%patterns% -e %1
goto :eof
