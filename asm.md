
## X86
https://low-level.readthedocs.io/en/latest/arch/x86/

## regs name
http://flint.cs.yale.edu/cs421/papers/x86-asm/asm.html
https://stackoverflow.com/questions/892928/why-are-x86-registers-named-the-way-they-are

## functionc calls
https://stackoverflow.com/questions/2535989/what-are-the-calling-conventions-for-unix-linux-system-calls-and-user-space-f

#### segment + index
DS:SI (DataSegment:SourceIndex)  to  to ES:DI(ExtraSegment:DestinationIndex), SI to rsi, di to rdi in x86_64

#### rdi
register destination index, first argument

#### rsi
register source index, second argument

#### rdx
register d extended, d means data

#### rcx
register c extended, c means counter, since it was used to hold a loop index.

#### rbx
register c extended, b means base

#### rax
register a extended, return reg, a means accumulator

#### r8
5th argument

#### r9
6th argument

## argument

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

### Instructions
- Machine instructions generally fall into three categories: data movement, arithmetic/logic, and control-flow.
- In assembly language, all the labels and numeric constants used as immediate operands.

## Data Movement Instructions
#### move
The mov instruction copies the data item referred to by its first operand (i.e. register contents, memory contents, or a constant value) into the location referred to by its second operand (i.e. a register or memory). While register-to-register moves are possible, direct memory-to-memory moves are not. 

#### push
Specifically, push first decrements ESP by 4, then places its operand into the contents of the 32-bit location at address (%esp)

#### pop
It first moves the 4 bytes located at memory location (%esp) into the specified register or memory location, and then increments ESP by 4.

#### lea
Load effective address, only the effective address is computed and placed into the register.

## Arithmetic and Logic Instructions
#### add, sub
#### inc, dec
Increment, Decrement
#### imul - Integer multiplication
Integer multiplication, The result (i.e. second) operand must be a register.
#### idiv - Integer division
The idiv instruction divides the contents of the 64 bit integer EDX:EAX.
The quotient result of the division is stored into EAX, while the remainder is placed in EDX.
#### and, or, xor — Bitwise logical and, or, and exclusive or
#### not - Bitwise logical not
Logically negates the operand contents
#### shl, shr - Shift left and right

## Control Flow Instructions
#### jmp 
#### jcondition
These instructions are conditional jumps that are based on the status of a set of condition codes that are stored in a special register called the machine status word.
#### comp
This instruction is equivalent to the sub instruction, except the result of the subtraction is discarded instead of replacing the first operand.

#### call
Subroutine call and return.The call instruction first pushes the current code location onto the hardware supported stack in memory.
Unlike the simple jump instructions, the call instruction saves the location to return to when the subroutine completes.
call = push(%rip + 1); jump <addr>;

#### ret
rety = jmp $(pop)
## Calling Convention
The C calling convention is based heavily on the use of the hardware-supported stack. It is based on the push, pop, call, and ret instructions. 
Subroutine parameters are passed on the stack. Registers are saved on the stack, and local variables used by subroutines are placed in memory on the stack.

Before calling a subroutine, the caller should save the contents of certain registers that are designated caller-saved. The caller-saved registers are EAX, ECX, EDX. Since the called subroutine is allowed to modify these registers, if the caller relies on their values after the subroutine returns, the caller must push the values in these registers onto the stack (so they can be restore after the subroutine returns.

EAX: subroutine return value

#### Callee Rules
The base pointer is used by convention as a point of reference for finding parameters and local variables on the stack.

Remember, the caller is not expecting the subroutine to change the value of the base pointer.
