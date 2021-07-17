20210206 (p19-p30)
#### Entering in the Program

These programs may overwhelm you at first. However, go through them with diligence.

Please tinker around with the programs as much as you can.

Assembling is the process that transforms what you typed into instructions for the machine.

The linker is the program that is responsible for putting the object files together and adding
information to it so that the kernel knows how to load and run it.

What is happening is that every program when it exits gives Linux an
exit status code, which tells it if everything went all right.

UNIX programs return numbers other than zero to indicate failure or
other errors, warnings, or statuses.

#### Outline of an Assembly Language Program

At the beginning there are lots of lines that begin with hashes (#). These are comments.

Get into the habit of writing comments in your code that will help them understand
both why the program exists and how it works.

Unfortunately, figuring out what is strange and what is straightforward comes mostly with experience.

Anything starting with a period isn’t directly translated into a machine instruction.

These are called assembler directives or pseudo-operations because they are handled by the assembler and are
not actually run by the computer.

The text section of a program is where the program instructions live.

This instructs the assembler that \_start is important to remember. \_start is a
symbol, which means that it is going to be replaced by something else either
during assembly or linking.

Symbols are generally used to mark locations of programs or data,
so you can refer to them by name instead of by their location number.

Symbols are used so that the assembler and linker can take care of keeping track of addresses, 
and you can concentrate on writing your program.

.globl means that the assembler shouldn’t discard this symbol after assembly, because the linker will need it.

\_start is a special symbol that always needs to be
marked with .globl because it marks the location of the start of the program.

defines the value of the  \_start label. A label is a symbol followed by a colon (symbol vs label). Labels define a symbol’s value.

When the assembler is assembling the program, it has to assign each data value and instruction an address.
Labels tell the assembler to make the symbol’s value be wherever the next instruction or data element will be.

Other instructions may have an operand hardcoded in. idivl, for example, 
requires that the dividend be in %eax, and %edx be zero, and the quotient is then transferred to
%eax and the remainder to %edx.

Some of these registers, like %eip and %eflags can only be accessed through special instructions.

but they have special meanings, special uses, or are simply faster when used in a specific way.

When you make a system call, which we will do shortly, the system call number has to be loaded into %eax.

The extra details, called parameters are stored in other registers.

Note that on x86 processors, even the general-purpose registers have some special purposes.

An interrupt interrupts the normal program flow, and transfers control from our program to Linux so that it will do a system call.

This is done by utilizing the letters a through f in addition to the regular digits.

#### Planning the Program

You might not think that something as simple as finding the maximum number from a list would take much planning.
