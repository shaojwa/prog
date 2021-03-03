
20210224 p129-p165

dynamic-linker: at program startup time.

#### How Shared Libraries Work

#### statically-linked executables
our first programs, all of the code was contained within the source file. 
Such programs are called statically-linked executables, because they contained all of the
necessary functionality for the program that wasn’t handled by the kernel.

When the helloworld program begins, the file /lib/ld-linux.so.2 is loaded first. This is the
dynamic linker.

The int before the function definition tell what type of value the function will return in %eax when it returns.

The reason that parameters are pushed in the reverse order is because of functions which
take a variable number of parameters like printf. The parameters pushed in last will be in
a known position relative to the top of the stack. The program can then use these parameters
to determine where on the stack the additional arguments are, and what type they are. For
example, printf uses the format string to determine how many other parameters are being
sent. If we pushed the known arguments first, you wouldn’t be able to tell where they were
on the stack.

Also, even when parameters shorter than a word are passed to functions, they are passed as longs on the stack.

The man page for ld.so contains a lot of information about how the Linux dynamic linker works.

Research the use of LD_PRELOAD

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

Each program gets its own sandbox to play in.
