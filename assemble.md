http://asm.sourceforge.net/articles/linasm.html
https://gist.github.com/mishurov/6bcf04df329973c15044

#### Opcode 
操作码

#### 指令码格式
```
[Optional instruction prefix] Operational-code [Optional modifier(s)] [Optional data element(s)]
```

## 处理器中的主要组件
#### 控制单元
1. 从内存中取指令
1. 指令解码
1. 从内存中读取数据
1. 存储结果
1. 指令预取
1. 分支预测
1. 乱序执行
1. 退出

#### 执行单元
1. 简单整数运算 （加减）
1. 复杂整数运算 （乘法）
1. 浮点运算

## 寄存器
#### 通用寄存器
8个寄存器用来存储工作数据
1. RAX，累加器，操作数，结果数据。
1. RBX，指向数据段的数据。
1. RCX，字串或者循环操作计数。
1. RDX，IO指针
1. RDI，字串操作的目标地址
1. RSI，字串操作的source地址。
1. RSP，栈顶指针。
1. RBP，栈底指针。

#### 段寄存器
6个16位的寄存器用来处理内存访问
1. 扁平内存模型
1. 分段内存模型
1. CS，代码段
1. DS，数据段
1. SS，堆段
1. ES，附加段
1. FS，附加段
1. GS，附加段

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

# AT&T 语法

## move data

```
// move rsp to rbp
mov    %rsp, %rbp 
```


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
