因为这是在.o文件中看的，在可执行文件中不会这样，如果要在.o文件中看，需要用-r参数来输出查看。
查看obj文件：
```
(gdb) disass reorder2
Dump of assembler code for function _Z8reorder2v:
   0x000000000000001f <+0>:     push   %rbp
   0x0000000000000020 <+1>:     mov    %rsp,%rbp
   0x0000000000000023 <+4>:     mov    0x0(%rip),%eax        # 0x29 <_Z8reorder2v+10>
   0x0000000000000029 <+10>:    add    $0x1,%eax
   0x000000000000002c <+13>:    mov    %eax,0x0(%rip)        # 0x32 <_Z8reorder2v+19>
   0x0000000000000032 <+19>:    movl   $0x0,0x0(%rip)        # 0x3c <_Z8reorder2v+29>
   0x000000000000003c <+29>:    pop    %rbp
   0x000000000000003d <+30>:    retq
```
查看link之后的executable：
```
(gdb) disass reorder2
Dump of assembler code for function _Z8reorder2v:
   0x0000000000402539 <+0>:     push   %rbp
   0x000000000040253a <+1>:     mov    %rsp,%rbp
   0x000000000040253d <+4>:     mov    0x201d55(%rip),%eax        # 0x604298 <gb>
   0x0000000000402543 <+10>:    add    $0x1,%eax
   0x0000000000402546 <+13>:    mov    %eax,0x201d48(%rip)        # 0x604294 <ga>
   0x000000000040254c <+19>:    movl   $0x0,0x201d42(%rip)        # 0x604298 <gb>
   0x0000000000402556 <+29>:    pop    %rbp
   0x0000000000402557 <+30>:    retq
```
用objdump 加r选项：
```
[wsh@node80 wsh]$ objdump -dr compile.o
compile.o:     file format elf64-x86-64

Disassembly of section .text:

0000000000000000 <_Z8reorder1ii>:
   0:   55                      push   %rbp
   1:   48 89 e5                mov    %rsp,%rbp
   4:   89 7d ec                mov    %edi,-0x14(%rbp)
   7:   89 75 e8                mov    %esi,-0x18(%rbp)
   a:   48 8d 45 ec             lea    -0x14(%rbp),%rax
   e:   48 89 45 f8             mov    %rax,-0x8(%rbp)
  12:   48 8b 45 f8             mov    -0x8(%rbp),%rax
  16:   48 89 45 f0             mov    %rax,-0x10(%rbp)
  1a:   8b 45 ec                mov    -0x14(%rbp),%eax
  1d:   5d                      pop    %rbp
  1e:   c3                      retq

000000000000001f <_Z8reorder2v>:
  1f:   55                      push   %rbp
  20:   48 89 e5                mov    %rsp,%rbp
  23:   8b 05 00 00 00 00       mov    0x0(%rip),%eax        # 29 <_Z8reorder2v+0xa>
                        25: R_X86_64_PC32       gb-0x4
  29:   83 c0 01                add    $0x1,%eax
  2c:   89 05 00 00 00 00       mov    %eax,0x0(%rip)        # 32 <_Z8reorder2v+0x13>
                        2e: R_X86_64_PC32       ga-0x4
  32:   c7 05 00 00 00 00 00    movl   $0x0,0x0(%rip)        # 3c <_Z8reorder2v+0x1d>
  39:   00 00 00
                        34: R_X86_64_PC32       gb-0x8
  3c:   5d                      pop    %rbp
  3d:   c3                      retq
```
