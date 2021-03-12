@echo off

if ["%1"]==[""] (
    echo Usage: %0 inFile
    goto :eof
)

set file=%~0p

set "groffPath=D:\groff\bin"
set "dformatPath=F:\dformat\src"

%dformatPath%\dformat.awk %1 | %groffPath%\troff -ms >out
