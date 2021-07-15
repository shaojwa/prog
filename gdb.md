1. https://sourceware.org/gdb/current/onlinedocs/gdb/
2. https://www.gnu.org/software/gdb/

## info Memory Mappings
You can double check if zero is valid using i proc m (short for info proc mappings)

## The $ Variable
```
(gdb) p mgmt_thread_data.next_thread
$67 = (struct k_thread *) 0x2000188c <eswifi0+48>
(gdb) p $.next_thread
$68 = (struct k_thread *) 0x200022ac <eswifi_spi0+20>
(gdb) <enter>
$69 = (struct k_thread *) 0x2000a120 <k_sys_work_q+20>
```

## batch mode
```
-batch
-ex command  // Execute given GDB command.
```

## set args
```
set args
```

## run
run with args

```
// method 1
$ gdb  --args /bin/dcache-dm-test --gtest_filter=mdtest.command_line

// method 2
$ gdb /bin/dcache-dm-test
(gdb) run --gtest_filter=mdtest.command_line

// method 3
$ gdb
(gdb) file /bin/dcache-dm-test
(gdb) set args --gtest_filter=mdtest.command_line
(gdb) run
```

## break
common breaks
```
break <linenum>
break filename:linenum
break filename:function
rbreak DMTest::WriteObj*
delete 4
```

breakpoint at address
```
break *0x0000000000400448
break *doupdate + 289
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
```

## info
list the memory regions of the binary currently being debugged.
```
info files 
```

local vars
```
info locals
```

args of the current stack frame
```
info args
```

all global and static variable names
```
info variables
```

eflags
```
info reg eflags
```

## list
```
 # 10 lines
list 10

# list function
list thread_routine
```

## examine
```
x /oxdutfcsi ADDRESS
x /i $rip
x $rdi
```

## display
```
display/i $rip
```

## disass
turn on disassemble
```
set  disassemble-next-line on
```

disass
```
disass
disass /m server::handle_readdir
disass /m main
disass $rip-10,$rip+10
```

disassemble next source line or insn when execution stops，it is good
```
set  disassemble-next-line on
show disassemble-next-line
```

## target
```
the executable gdb started is the target.
the core-file gdb specified is the target.
the process after run in gdb is the target.
```

## info
info files
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

## reverse step
https://stackoverflow.com/questions/1206872/how-to-go-to-the-previous-line-in-gdb
```
Target multi-thread does not support this command.
```

## layout 
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

## hooks
https://sourceware.org/gdb/current/onlinedocs/gdb/Hooks.html
```
# put this into ~/.gdbinit:
define hook-next
  info locals
end
```

## auto complete the template-function name 
using <tab> to break a template-function
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
