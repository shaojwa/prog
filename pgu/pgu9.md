
20210224 p129-p135

dynamic-linker: at program startup time.

#### How Shared Libraries Work

#### statically-linked executables
our first programs, all of the code was contained within the source file. 
Such programs are called statically-linked executables, because they contained all of the
necessary functionality for the program that wasn’t handled by the kernel.

When the helloworld program begins, the file /lib/ld-linux.so.2 is loaded first. This is the
dynamic linker.
