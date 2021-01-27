http://flint.cs.yale.edu/cs421/papers/x86-asm/asm.html

## x86 Assembly Guide
#### abstract
the basics of 32-bit x86 assembly language programming

#### assembler
gnu assember, gas

#### Registers
1. general purpose registers.
1. he register names are mostly historical.
1. EAX used to be called the accumulator since it was used by a number of arithmetic operations.
1. ECX was known as the counter since it was used to hold a loop index.
1. most of the registers have lost their special purposes in the modern instruction set.
1. by convention, two are reserved for special purposes, the stack pointer (ESP) and the base pointer (EBP).

## Memory and Addressing Modes
1. You can declare static data regions in x86 assembly using special assembler directives for this purpose.
1. To refer to the address of the data created, we can label them.
1. Arrays in x86 assembly language are simply a number of cells located contiguously in memory.

#### Addressing Memory
mem to reg:
```
mov (%ebx), %eax
mov -4(%esi), %eax
mov %cl, (%esi,%eax,1)   	/* Move the contents of CL into the byte at address ESI+EAX. */
mov (%esi,%ebx,4), %edx   /* Move the 4 bytes of data at address ESI+4*EBX into EDX. */
```
pay attention to the multi-regs operations

#### Operation Suffixes
```
movb $2, (%ebx)	/* Move 2 into the single byte at the address stored in EBX. */
movw $2, (%ebx)	/* Move the 16-bit integer representation of 2 into the 2 bytes starting at the address in EBX. */
movl $2, (%ebx) /* Move the 32-bit integer representation of 2 into the 4 bytes starting at the address in EBX. */
```

## Instructions
- Machine instructions generally fall into three categories: data movement, arithmetic/logic, and control-flow.
- In assembly language, all the labels and numeric constants used as immediate operands.

#### Data Movement Instructions
- move
The mov instruction copies the data item referred to by its first operand (i.e. register contents, memory contents, or a constant value) into the location referred to by its second operand (i.e. a register or memory). While register-to-register moves are possible, direct memory-to-memory moves are not. 
- push
Specifically, push first decrements ESP by 4, then places its operand into the contents of the 32-bit location at address (%esp)
- pop
It first moves the 4 bytes located at memory location (%esp) into the specified register or memory location, and then increments ESP by 4.
-lea
Load effective address
