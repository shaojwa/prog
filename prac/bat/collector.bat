::v0.1@20160316

@echo off
set log=%~p0\run.log
set javahome=C:\Program Files\Java\jdk1.7.0_79

:: set default values
set action=usage
set debug=0

del %log%
:: process args

:loop
if [%1]==[] goto next_step

if [%1]==[start] (
    set action=%1
) else if [%1]==[stop] (
    set action=%1
) else if [%1]==[restart] (
    set action=%1
) else if [%1]==[status] (
    set action=%1
) else if [%1]==[-v] (
    set verbose=1
) else if [%1]==[--verbose] (
    set verbose=1
) else (
    set args=%args% %1
)
shift 
goto loop
:next_step

echo action=%action%>>%log%
echo verbose=%verbose%>>%log%
echo args=%args%>>%log%

call :setting_soc_env
call :setting_java_env
call :setting_extra_module_report_birt

echo base=%base%>>%log%
echo PROFILE_HOME=%PROFILE_HOME%>>%log%
echo SOC_HOME=%SOC_HOME%>>%log%
echo LIB_DIR=%LIB_DIR%>>%log%
echo SOC_BIRT_HOME=%SOC_BIRT_HOME%>>%log%
echo SOC_BIRT_LIB=%SOC_BIRT_LIB%>>%log%
echo CLASSPATH=%CLASSPATH%>>%log%


if [%action%]==[start] (
    call :start
) else if [%action%]==[stop] (
    call :stop
) else if [%action%]==[restart] (
    call :restart
) else if [%action%]==[status] (
    call :status
) else (
    call :usage
)


::unset variables
set action=
set args=
set verbose=
set debug=
set javahome=
set JAVA_HOME=
set base=
set PROFILE_HOME=
set SOC_HOME=
set LIB_DIR=
set CLASSPATH=
set SOC_BIRT_HOME=
set SOC_BIRT_LIB=
goto :eof


:setting_soc_env
echo func: setting_soc_env>>%log%
set batpath=%~p0
cd %~p0\..
set base=%cd%
set PROFILE_HOME=%base%
cd ..\..
set socpath=%cd%
if [%SOC_HOME%]==[] (
    set SOC_HOME=%socpath%
)
set  LIB_DIR=%SOC_HOME%\lib
if not exist %LIB_DIR% (
    set LIB_DIR=%PROFILE_HOME%\lib
)

if not exist %PROFILE_HOME%\conf (
    echo %PROFILE_HOME%\conf not exist
)
set CLASSPATH=%PROFILE_HOME%\conf;%LIB_DIR%\*

goto :eof


:setting_java_env
echo func: setting_java_env>>%log%
set JAVA_HOME=%javahome%
set PATH=%JAVA_HOME%\bin;%PATH%

:: set jvm setting for heap size
set JAVA_OPTS=-Xms1G -Xmx1G -XX:MaxPermSize=256m -Djava.awt.headless=true 

set JAVA_OPTS=%JAVA_OPTS% -XX:+UseCompressedOops 

set JAVA_OPTS=%JAVA_OPTS% -XX:+PrintGC -XX:+PrintGCDetails -XX:+PrintGCTimeStamps

set JAVA_OPTS=%JAVA_OPTS% -Djava.util.logging.config.file=%PROFILE_HOME%\conf\logging.properties
echo PATH=%PATH%>>%log%
goto :eof

:setting_extra_module_report_birt
echo func: setting_extra_module_report_birt>>%log%
if not EXIST %SOC_HOME%\platform (
    echo "error: not platform in %SOC_HOME%
)
set SOC_BIRT_HOME=%SOC_HOME%\platform
set SOC_BIRT_LIB=%SOC_BIRT_HOME%\lib
set CLASSPATH=%CLASSPATH%;%SOC_BIRT_LIB%\*
goto :eof



:start
echo func: start>>%log%
echo JAVA_OPTS=%JAVA_OPTS%>>%log%
echo args=%args%>>%log%
cd %PROFILE_HOME%
start /B java %JAVA_OPTS% com.wibu.xpm.Wrapper 1>logs/console.log 2>&1
goto :eof


:stop
echo function-start
goto:eof


:restart
call :stop
call :start
goto :eof


:: functions
:usage
echo Usage: %~nx0 (start^|stop^|restart^|status) [-v^|--verbose]
goto :eof
