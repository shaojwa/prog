#### mode字段多一个点号

    [wsh@dev bin]$ ll -i /bin/which
    3516 -rwxr-xr-x. 1 root root 24336 Jun 10  2014 /bin/which
    [wsh@dev bin]$ ll -i /usr/bin/which
    3516 -rwxr-xr-x. 1 root root 24336 Jun 10  2014 /usr/bin/which


    According to [ls.c](http://git.savannah.gnu.org/cgit/coreutils.git/tree/src/ls.c?id=v8.21#n3785) (line 3785)  
    . means an [SELinux ACL](https://en.wikipedia.org/wiki/Security-Enhanced_Linux)  
    + means a [general ACL](https://en.wikipedia.org/wiki/Access_control_list#Filesystem_ACLs)  


    info coreutils 'ls invocation'
    
In the section describing "-l" (--format=long):

    Following the file mode bits is a single character that specifies
    whether an alternate access method such as an access control list
    applies to the file.  When the character following the file mode
    bits is a space, there is no alternate access method.  When it is
    a printing character, then there is such a method.

    GNU `ls' uses a `.' character to indicate a file with an SELinux
    security context, but no other alternate access method.

    A file with any other combination of alternate access methods is
    marked with a `+' character.


Linux下的访问一直在发展，目前有三种：

DAC，谨慎访问控制，DAC就是最常见的mode位，是最先校验的控制位。

ACL，POSIX ACL，ACL简单说就是更加精细的访问控制，针对用户，用户组，都可以针对某个特定用户用户组设定权限。通过getfact和setfact进行读取和设置。

MAC，强制访问控制。SELinux就是最常见的一种MAX，控制更加的精细，不只是针对文件，可以针对端口，socket，等逻辑和物理设备都可以被控制，甚至比如防火墙一类的service也可以。 MAC通常是一种基于策略（policy）的访问控制，在具体实现中，策略（policy）都长以规则（rule）的形式实现
 
 
 
 
 
