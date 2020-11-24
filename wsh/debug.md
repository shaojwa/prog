1. https://www.gnu.org/software/gdb/

https://sourceware.org/gdb/current/onlinedocs/gdb/

#### get help

#### set args

#### reak
```
break filename:linenum
break filename:function
```

#### rbreak

#### print class
print dentry infos
```
p *(Dentry*)0x7f183001e400
```

#### print class field
```
(gdb) p ((Inode*)0x7f183001cb70)->ll_ref
$6 = 0
(gdb) p ((Inode*)0x7f183001cb70)->_ref
$7 = 1
```
print Dentry.ref
```
p ((Dentry*)0x7f183001e400)->ref
$8 = 0
```
