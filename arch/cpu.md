## The main components in the processor:
#### Control unit
1. retrieve instructions from memory
1. Decode  instructions for operation
1. Retrieve data from memory as needed
1. Store the result as necessary
1. Instruction prefectch and decoding
1. Branch prediction
1. out-of-order execution
1. retirement

## registers
#### general-purpose registers
1. %rax, 1st return register, number of vecrtor regeister used.
1. %rbx, callee-saved register, base pointer.
1. %rcx, pass 4th argument to function.
1. %rdx, pass 3rd argument to function，2nd return register
1. %rsi, used to pass 2th argument to function1.
1. %rdi, used to pass 1th argument to function.
1. %rsp, stack pointer, it is used
1. %rbp, callee-saved register, frame pointer.
1. %r8, used to pass 5th argument to function
1. %r9, used to pass 6th argument to function
1. %r10
1. %r11
1. %r12
1. %r13
1. %r14
1. %r15

#### segment register
x86 memory segmentation refers to the implementation of memory segmentation in the Intel x86 computer instruction set architecture.
Segmentation was introduced on the Intel 8086 in 1978 as a way to allow programs to address more than 64 KB (65,536 bytes) of memory.
The Intel 80286 introduced a second version of segmentation in 1982 that added support for virtual memory and memory protection.
At this point the original model was renamed real mode, and the new version was named protected mode.

#### drop segments
The x86-64 architecture, introduced in 2003, has largely dropped support for segmentation in 64-bit mode.

#### CS/DS/SS/ES
In both real and protected modes, the system uses 16-bit segment registers to derive the actual memory address.
CS(code segment), DS(data segment), SS(stack segment),ES(extra segment, is the default destination for string operations).

#### FS/GS
The Intel 80386, introduced in 1985, adds two additional segment registers, FS and GS, with no specific uses defined by the hardware. 
the Linux kernel uses the GS segment to store per-CPU data.
Current Linux also uses GS to point to thread-local storage.

####  float register
six 80bit

#### control register
CR0-CR4

#### debug register
eight 32bit registers

## read mode and protect mode
#### 8086, 1978, add read-mode, linear space = 1M)
1. linear adress is 20bit = segment_reg(16bit) << 4 + offset_bit

#### 80286, 1982, virtual memory and memory protection
1. segment base is 24bit
1. offset is 16bit
1. linear_adress is 24bit = LDT[seg_reg(16bit)](24bit) + 0ffset_bit
1. LDT, local discriptor table, item = linear_address_base + limit

#### 80386, 1985, add FS/GS
1. paging unit has been added as a second layer of address translation between the segmentation unit and the physical bus.
1. segment base is 32bit
1. offset is 32bit
1. linear_address is 32bit
1. The paging unit may be enabled or disabled; 

#### x86-64
1. The x86-64 architecture does not use segmentation in long mode (64-bit mode).
1. Four of the segment registers, CS, SS, DS, and ES, are forced to 0, and the limit to 2^64.
1. The segment registers FS and GS can still have a nonzero base address.
1. This allows operating systems to use these segments for special purposes. 

#### segment practice
```
CS  0x33
DS  0x2b
SS  0
ES  0
FS  0
GS  0
```

#### why CS  is not zero

#### IP
Instruction pointer

#### what is preserved across function calls
http://www.x86-64.org/documentation/abi.pdf (page 20)
