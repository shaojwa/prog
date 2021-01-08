http://www.x86-64.org/documentation/abi.pdf (page 20)

#### argument placement 
Linux (and Windows) x86-64 calling conventionhas the first few arguments noton the stack, but in registers instead
See http://www.x86-64.org/documentation/abi.pdf (page 20) Specifically:
If the class is MEMORY, pass the argument on the stack.
If the class is INTEGER, the next available register of the sequence %rdi, %rsi, %rdx, %rcx, %r8 and %r9 is used.
If the class is SSE, the next available vector register is used, the registers are taken in the order from %xmm0 to %xmm7.
If the class is SSEUP, the eightbyte is passed in the next available eightbyte chunk of the last used vector register.
If the class is X87, X87UP or COMPLEX_X87, it is passed in memory.
The INTEGERclass is anything that will fit in a general purpose register
