20210305 p181-196

Well, the XOR operation is faster than the loading operation, so many programmers use it to
load a register with zero. For example, the code `movl $0, %eax` is often replaced by `xorl %eax, %eax`

`andl $0b00000000000000000000000000000001, %eax`
`cmpl $0b00000000000000000000000000000001, %eax`

When a number represents a set of options for a function or system call, the individual true/false elements are called flags.

there is a register called the program status register. This register holds a lot of information about what happens in a computation.
