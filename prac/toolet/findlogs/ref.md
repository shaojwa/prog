收集到的相关操作系统以及主要服务对应的日志目录
@20150309

/////////////////////////////////
// linux
/////////////////////////////////


d klog
d log
d logs
/etc/httpd/logs
/root/tomcat7/logs


d syslog
/opt/scanner/front/webapps/ROOT/static/js/syslog
/opt/scanner/front/webapps/ROOT/WEB-INF/velocity/admin/syslog
/root/tomcat7/webapps/ROOT/static/js/syslog
/root/tomcat7/webapps/ROOT/WEB-INF/velocity/admin/syslog
/usr/lib/golang/src/log/syslog
/usr/local/go/src/log/syslog
/usr/share/ruby/syslog


f loginlog


f syslog
/etc/logrotate.d/syslog
/var/log/anaconda/syslog
/sys/fs/selinux/class/capability2/perms/syslog


f messages
/var/log/messages : General message and system related stuff


f sulog


//
// linux OS
//
/var/log/messages : General message and system related stuff
/var/log/auth.log : Authenication logs
/var/log/kern.log : Kernel logs
/var/log/cron.log : Crond logs (cron job)
/var/log/maillog : Mail server logs
/var/log/qmail/ : Qmail log directory (more files inside this directory)
/var/log/httpd/ : Apache access and error logs directory
/var/log/lighttpd/ : Lighttpd access and error logs directory
/var/log/boot.log : System boot log
/var/log/mysqld.log : MySQL database server log file
/var/log/secure or /var/log/auth.log : Authentication log
/var/log/utmp or /var/log/wtmp : Login records file
/var/log/yum.log : Yum command log file.


//
//apache
//
/var/log/httpd/error_log    //CentOS
/var/log/apache/access.log
/var/log/appache2/access.log
/var/log/appache2/error.log // apache-Debian
/var/log/appache2/error.log // apache-Ubuntu
/var/log/httpd-error.log    // apache-FreeBSD
/var/log/tomcat6/
/etc/httpd/logs


// Tomcat
/root/tomcat7/logs


//nginx
logs/error.log
logs/access.log


//////////////////////////////////
// Windows
//////////////////////////////////

d winevt
d config


//
// Windows OS logs
//
%SystemRoot%\System32\Config          Win2000/2003/XP
%SystemRoot%\system32\winevt\logs     Win2008/Vista/7/8/10

//Application
%SystemRoot%\System32\Winevt\Logs\Application.evtx
//Forwarded Events
%SystemRoot%\System32\Confi g\FordwardedEvents.evtx
//Security
%SystemRoot%\System32\Winevt\Logs\Security.evtx


//Application and Services logs

//DFS Replication
%SystemRoot%\System32\Winevt\Logs\DfsReplication.evtx

//DNS Server
%SystemRoot%\System32\Winevt\Logs\DNS Server.evtx

//Hardware Events
%SystemRoot%\System32\Config\HardwareEvents.evtx

//IIS-log
%SystemDrive%\inetpub\logs\LogFiles
//IIS-error log
%SystemDrive%\Windows\System32\LogFiles\HTTPERR
