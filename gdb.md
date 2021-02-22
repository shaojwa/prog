1. https://sourceware.org/gdb/current/onlinedocs/gdb/
1. https://www.gnu.org/software/gdb/

#### 查看eflags寄存器的值
```
info reg eflags
```

#### 开启汇编指令就可以看到当前执行的指令

```
set  disassemble-next-line on
```

#### reverse step
https://stackoverflow.com/questions/1206872/how-to-go-to-the-previous-line-in-gdb
```
Target multi-thread does not support this command.
```

#### disass
```
disass /m main
disass $rip-10,$rip+10
```
  
#### examine address
```
x /oxdutfcsi ADDRESS
x /i $rip
```

#### disassemble next source line or insn when execution stops
it is good
```
set  disassemble-next-line on
show disassemble-next-line
```

#### breakpoint at address
```
break *0x0000000000400448
```

#### run with args
```
gdb /bin/dcache-dm-test
(gdb) r --gtest_filter=mdtest.command_line
```
#### show local vars
```
info locals
```

#### args of the current stack frame
```
info args
```

#### all global and static variable names
```
info variables
```

#### layout 
```
layout asm
layout src
```
Enter / leave the TUI mode with one of this combinations:
```
ctrl + a
```
control the register window
```
tui reg  float/genetal/next/system
```

#### hooks
https://sourceware.org/gdb/current/onlinedocs/gdb/Hooks.html
```
# put this into ~/.gdbinit:
define hook-next
  info locals
end
```
  
##### auto disassemble the next line or insn when execution stops
```
set disassemble-next-line on
show disassemble-next-line
```
#### auto complete the template-function name 

using <tab> to break a template-function
  
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
