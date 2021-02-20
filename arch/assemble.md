## Opcode 
#### Instruction Code Format (IA-32)
- Optional instruction prefix
- Operational code
- Optional modifier(s)
- Optional data element(s)

##  Flags
#### Status flags
#### Control flags
#### System flags

## AT&T Assembly Syntax
http://flint.cs.yale.edu/cs421/papers/x86-asm/asm.html

#### Data Movement Instructions
move
```
move [data] [addess]
Syntax
mov <reg>, <reg>
mov <reg>, <mem>
mov <mem>, <reg>
mov <con>, <reg>
mov <con>, <mem>
```

push
```
// push rbp tiostack
push   %rbp 
```

```
// LEA (load effective address)
// https://stackoverflow.com/questions/1658294/whats-the-purpose-of-the-lea-instruction
lea    -20(%rbp), %rax 
```

```
sub   $32, %rsp
```

#### argument placement
Linux (and Windows) x86-64 calling conventionhas the first few arguments noton the stack, but in registers instead
See http://www.x86-64.org/documentation/abi.pdf (page 20), Specifically:
If the class is MEMORY, pass the argument on the stack.
If the class is INTEGER, the next available register of the sequence %rdi, %rsi, %rdx, %rcx, %r8 and %r9 is used.


#### lesson 1
https://zhuanlan.zhihu.com/p/23618489
```
$ nasm -f elf first.asm -o first.o
$ gcc -m32 first.o -o first
```
http://asm.0x233.com/run

#### lession 2
```
mov add ret sub
```

#### lesson 3
att memroy access：
```
0x34a8(%rdx),%rdx
```
- xchg
- nop
#### lession 4
