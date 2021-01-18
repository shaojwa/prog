1. https://web.stanford.edu/class/archive/cs/cs107/cs107.1194/guide/x86-64.html
1. https://docs.oracle.com/cd/E19641-01/802-1948/802-1948.pdf
1. http://asm.sourceforge.net/articles/linasm.html
1. https://gist.github.com/mishurov/6bcf04df329973c15044
1. http://abcdxyzk.github.io/blog/2012/11/23/assembly-args/
1. http://www.x86-64.org/documentation/abi.pdf
1. http://asm.0x233.com/run
1. http://flint.cs.yale.edu/cs421/papers/x86-asm/asm.html
1. https://low-level.readthedocs.io/en/latest/arch/x86/
1. https://breakdev.org/x86-shellcode-obfuscation-part-2/
1. https://x86.lol/generic/2019/07/04/kernel-entry.html
1. https://software.intel.com/sites/default/files/managed/39/c5/325462-sdm-vol-1-2abcd-3abcd.pdf

## Opcode 
#### Instruction Code Format (IA-32)
- Optional instruction prefix
- Operational code
- Optional modifier(s)
- Optional data element(s)

## The main components in the processor:
#### Control unit
1. 从内存中取指令
1. 指令解码
1. 从内存中读取数据
1. 存储结果
1. 指令预取
1. 分支预测
1. 乱序执行
1. 退出

####  Execution unit
1. 简单整数运算 （加减）
1. 复杂整数运算 （乘法）
1. 浮点运算

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

#### CS
#### DS
#### SS
#### ES

#### FS
FS is used as canary-based stack protector.
On x86_64, segmented addressing is no longer used, but both the FS and GS registers can be used as base-pointer addresses in order to access special operating system data-structures. So what you're seeing is a value loaded at an offset from the value held in the FS register, and not bit manipulation of the contents of the FS register.

FS:0x28 on Linux is storing a special sentinel stack-guard value, and the code is performing a stack-guard check. 

#### GS
GS is also used in gcc's thread-local storage.

#### IP 指令指针
Instruction pointer

#### 浮点寄存器
6个80bit长的寄存器

#### 控制寄存器
CR0-CR4

#### 调试寄存器
8个32位的寄存器

## 标记
#### 状态标识
1. CF 进位标识
1. PF 校验位
1. ZF 零标识
1. SF 符号标识
1. OF 溢出标识

#### 控制标记
DF flag

#### 系统标记
10个，分别是：
1. 陷阱标记。
1. 中断使能标记。
1. IO优先级标记。
1. 嵌套任务标记。
1. 中继标记。
1. 虚拟8086模式标记。
1. 对齐检查标记。
1. 虚拟中断标记。
1. 虚拟中断等待标记。
1. 认证标记。

## AT&T Assembly Syntax
http://flint.cs.yale.edu/cs421/papers/x86-asm/asm.html

#### Data Movement Instructions
move
```
move [data] [addess]
Syntax
mov <reg>, <reg>
mov <reg>, <mem>
mov <mem>, <reg>
mov <con>, <reg>
mov <con>, <mem>
```

push
```
// push rbp ti stack
push   %rbp 
```

```
// LEA (load effective address)
// https://stackoverflow.com/questions/1658294/whats-the-purpose-of-the-lea-instruction
lea    -20(%rbp), %rax 
```

```
sub   $32, %rsp
```

#### argument placement
Linux (and Windows) x86-64 calling conventionhas the first few arguments noton the stack, but in registers instead
See http://www.x86-64.org/documentation/abi.pdf (page 20), Specifically:
If the class is MEMORY, pass the argument on the stack.
If the class is INTEGER, the next available register of the sequence %rdi, %rsi, %rdx, %rcx, %r8 and %r9 is used.


#### lesson 1
https://zhuanlan.zhihu.com/p/23618489
```
$ nasm -f elf first.asm -o first.o
$ gcc -m32 first.o -o first
```
http://asm.0x233.com/run

#### lession 2
```
mov add ret sub
```

#### lesson 3
att memroy access：
```
0x34a8(%rdx),%rdx
```
- xchg
- nop
#### lession 4
