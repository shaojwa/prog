#### mode字段多一个点号

  [wsh@dev bin]$ ll -i /bin/which
  3516 -rwxr-xr-x. 1 root root 24336 Jun 10  2014 /bin/which
  [wsh@dev bin]$ ll -i /usr/bin/which
  3516 -rwxr-xr-x. 1 root root 24336 Jun 10  2014 /usr/bin/which


According to [ls.c](http://git.savannah.gnu.org/cgit/coreutils.git/tree/src/ls.c?id=v8.21#n3785) (line 3785)  
\. means an [SELinux ACL](https://en.wikipedia.org/wiki/Security-Enhanced_Linux)  
\+ means a [general ACL](https://en.wikipedia.org/wiki/Access_control_list#Filesystem_ACLs)  


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
