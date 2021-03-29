1. https://sourceware.org/gdb/current/onlinedocs/gdb/
1. https://www.gnu.org/software/gdb/

## target
```
the executable gdb started is the target.
the core-file gdb specified is the target.
the process after run in gdb is the target.
```

## info files
```
 0x000055d3b9455000 - 0x000055d3b9456000 is load1a
 0x000055d3b9456000 - 0x000055d3b9456000 is load1b
 0x000055d3ba7c5000 - 0x000055d3ba7e8000 is load2
 0x000055d3ba7e8000 - 0x000055d3baa88000 is load3
 0x000055d3baa88000 - 0x000055d3badde000 is load4
 0x00007f4970000000 - 0x00007f4a70000000 is load5
 0x00007f4a70800000 - 0x00007f4b70800000 is load6
 0x00007f4b71000000 - 0x00007f4b72001000 is load7
 0x00007f4b72800000 - 0x00007f4b75a01000 is load8
 0x00007f4b75a01000 - 0x00007f4b75a02000 is load9
 0x00007f4b75a02000 - 0x00007f4b76001000 is load10
```

#### examine eflags
```
info reg eflags
```

#### turn on disassemble

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
