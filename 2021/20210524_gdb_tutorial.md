http://www.brendangregg.com/blog/2016-08-09/gdb-example-ncurses.html

## 1. The Problem
Note that it says "Segmentation fault" and not "Segmentation fault (core dumped)". I'd like a core dump to debug this.

## 2. Fixing Core Dumps
%e	executable filename (may be shortened), but dse is not!

## 3. Starting GDB

## 4. Back Trace
1. It's usually the first command I use in a gdb session.
2. The "??" entries are where symbol translation failed.
3. Stack walking – which produces the stack trace – can also fail. 

## 5. Disassembly

## 6. Check Registers
Printing register state using i r (short for info registers).
Well, %rsi is zero. There's our problem! Zero is unlikely a valid address, 
and this type of segfault is a common software bug: dereferencing an uninitialized or NULL pointer.

## 7. Memory Mappings
```
```
## 10. Reverse Stepping

```
(gdb) record
```

## 12. Source Code
```
(gdb) disas/s
```

## 13. TUI

## 15. info symbol
```
info symbol set_curterm
```

## 19. write memory
```
set $rdi=0xbecb90
```

## 20. Conditional Breakpoints
```
cond 1 $rdi==0x0
``
