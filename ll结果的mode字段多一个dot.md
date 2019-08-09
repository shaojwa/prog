#### ll结果的mode字段多一个点号

  [wsh@dev bin]$ ll -i /bin/which
  3516 -rwxr-xr-x. 1 root root 24336 Jun 10  2014 /bin/which
  [wsh@dev bin]$ ll -i /usr/bin/which
  3516 -rwxr-xr-x. 1 root root 24336 Jun 10  2014 /usr/bin/which


According to [ls.c](http://git.savannah.gnu.org/cgit/coreutils.git/tree/src/ls.c?id=v8.21#n3785) (line 3785)  
. means an [SELinux ACL](https://en.wikipedia.org/wiki/Security-Enhanced_Linux)  
+ means a [general ACL](https://en.wikipedia.org/wiki/Access_control_list#Filesystem_ACLs)  
