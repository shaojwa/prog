The Intel 80386, introduced in 1985, adds two additional segment registers, FS and GS, with no specific uses defined by the hardware.

#### FS
FS, is used as canary-based stack protector. On x86_64, segmented addressing is no longer used,
but both the FS and GS registers can be used as base-pointer addresses in order to access special operating system data-structures.
So what you're seeing is a value loaded at an offset from the value held in the FS register, and not bit manipulation of the contents of the FS register.

FS:0x28 on Linux is storing a special sentinel stack-guard value, and the code is performing a stack-guard check. 

#### GS
GS is also used in gcc's thread-local storage.

