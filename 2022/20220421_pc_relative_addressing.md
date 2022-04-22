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
查看link之后的ELF文件：
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
