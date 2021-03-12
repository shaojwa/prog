@echo off
rem 监控服务进程是否正在运行，如果退出重新启动
rem created on 20160801 v.01
rem 配置说明:
rem servivceName用来配置服务名，默认是参数传入，也可以固定。
rem waitSeconds就是间隔默认的监控间隔时间，默认是300秒
rem 进程单例运行由调用进程控制，脚本本身不做校验。


set serviceName=%1
set waitSeconds=300

if [%serviceName%] == [""] (
    echo Usage: %~nx0 serviceName
)

set servicePort=1444

set /a waitSeconds=%waitSeconds%+1
rem echo %waitSeconds%

:loop_begin
rem echo %waitSeconds%
ping  127.0.0.1 -n %waitSeconds% > nul
sc query %serviceName%  > nul
set ret=%errorlevel%
echo sc query returns %ret%
if %ret% NEQ 0 (
    sc start %serviceName% > nul
)

netstat -ano | findstr %servicePort%
set ret=%errorlevel%
echo netstat returns %ret%
if %ret% NEQ 0 (
    sc start %serviceName% > nul
)
goto :loop_begin

set watiSeconds=
set serviceName=
set ret=
set servicePort=

