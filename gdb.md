1. https://sourceware.org/gdb/current/onlinedocs/gdb/
1. https://www.gnu.org/software/gdb/

## tips
1. using <tab> to break a template-function
1. break *0x0000000000400448
1. disass /m main
1. disass $rip-10,$rip+10
1. layout asm
1. layout src
1. x/i $rip
1. info locals
1. info variables
1. info args


#### run with args
```
gdb /bin/dcache-dm-test
(gdb) r --gtest_filter=mdtest.command_line
```
  
#### hooks
https://sourceware.org/gdb/current/onlinedocs/gdb/Hooks.html
```
# put this into ~/.gdbinit:
define hook-next
  info locals
end
```
  
#####
```
set  disassemble-next-line on
show disassemble-next-line
```

## breakpoints
```
break filename:linenum
break filename:function
rbreak DMTest::WriteObj*
break *0x0000000000400448
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
info locals
```

## running
```
attach
detach
n(next)
ni(nexti)
r(run)
s(step)
rn(reverse-next) Target multi-thread does not support this command
rs(reverse-step) Target multi-thread does not support this command
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
