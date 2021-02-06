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

This instructs the assembler that _start is important to remember. _start is a
symbol, which means that it is going to be replaced by something else either
during assembly or linking.

Symbols are generally used to mark locations of
programs or data, so you can refer to them by name instead of by their location
number.

