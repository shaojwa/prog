1. https://sourceware.org/gdb/current/onlinedocs/gdb/
1. https://www.gnu.org/software/gdb/


#### get help
```
Type "help" followed by a class name for a list of commands in that class.
Type "help all" for the list of all commands.
Type "help" followed by command name for full documentation.
Type "apropos word" to search for commands related to "word".
```

#### class of commands
```
aliases -- Aliases of other commands
breakpoints -- Making program stop at certain points
data -- Examining data
files -- Specifying and examining files
internals -- Maintenance commands
obscure -- Obscure features
running -- Running the program
stack -- Examining the stack
status -- Status inquiries
support -- Support facilities
tracepoints -- Tracing of program execution without stopping the program
user-defined -- User-defined commands
```
## running
#### set args

## breakpoints
#### break
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

#### issues and tips
1. using <tab> to break a template-function
