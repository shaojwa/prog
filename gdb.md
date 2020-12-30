1. https://sourceware.org/gdb/current/onlinedocs/gdb/
1. https://www.gnu.org/software/gdb/

## tips
1. using <tab> to break a template-function
1. disass /m main
1. l
1. si
1. x/i $rip

## breakpoints
```
break filename:linenum
break filename:function
rbreak DMTest::WriteObj*
delete 4
```

## data
```
p ((Inode*)0x7f183001cb70)->ll_ref
p ((Inode*)0x7f183001cb70)->_ref
p *(Dentry*)0x7f183001e400
p $rdi
p /x $rdi
p /d $rdi
p /u $rdi
p /o $rdi
p /t $rdi
disass
disass /m server::handle_readdir
set args
x $rdi
x/i $rip
display/i $rip
```

## stack
```
bt
frame
```

## status
```
info addr obj_locate_snap
info symbol 0x7f5b6879750c 
info thread
info reg rdi
info vtbl this
```

## running
```
attach
detach
n(next)
ni(nexti)
r(run)
s(step)
si(stepi)
thread 4
thread apply
thread find
```

## class of commands
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
  
## get help
```
Type "help" followed by a class name for a list of commands in that class.
Type "help all" for the list of all commands.
Type "help" followed by command name for full documentation.
Type "apropos word" to search for commands related to "word".
```
