20210224 p149-
#### The Memory Layout of a Linux Program

The actual instructions (the .text section) are loaded at the address 0x08048000
(numbers starting with 0x are in hexadecimal, which will be discussed in Chapter
10). The .data section is loaded immediately after that, followed by the .bss
section.


The last byte that can be addressed on Linux is location 0xbfffffff. Linux starts the
stack here and grows it downward toward the other sections. Between them is a
huge gap. The initial layout of the stack is as follows: At the bottom of the stack
(the bottom of the stack is the top address of memory - see Chapter 4), there is a
word of memory that is zero. After that comes the null-terminated name of the
program using ASCII characters. After the program name comes the program’s
environment variables (these are not important to us in this book). Then come the
program’s command-line arguments.
