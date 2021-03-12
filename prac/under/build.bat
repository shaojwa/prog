

:: on 20140820
@echo off

cd /d %~dp0

if [%1]==[debug] (
    echo build debug...
    nmake /f makefile debug=1
) else (
    echo build release...
    nmake /f makefile release=1
)

if [%1]==[clean] (
   nmake /f makefile clean
)