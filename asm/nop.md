## nop
No operation

## Description
No operations are performed by nop. The xchgl %eax, %eax instruction is an alias for the nop instruction.

## sample
// nopw is equals to nop twice.
```
nopw   0x0(%rax,%rax,1)
```

## Why in need
nop's effect on the CPU is to increment IP/EIP by 1.
The nopw equivalents will do so by 2.
nop just takes some space in .text section of code.
make the next instruct begins on a patricular memory boundary.
for example, nopw usually makes the next instruction begin address with 16-bit aligned.

## Why has oprerand
**it's gas syntax**
ref to [operands to NOP on AMD64](http://john.freml.in/amd64-nopl)

> they could opt to use more complex NOP instructions to provide hints like memory prefetch requests.
> On processors without the prefetch logic the operations would do nothing,
  but processors with prefetch would initiate memory requests to bring the data into cache. 

really for prefetch?

> Aligning jump targets in code to a 16-byte boundary to make sure that the target can be fetched in a single cacheline request is important.
> However the padding used to flow through to this aligned boundary should be as efficiently encoded as possible.

so, it works for the prefetch, but also as efficiently encoded as possible.
```
nopw   %cs:0x0(%rax,%rax,1)
```
takes 8 bytes, but 
```
nopw  0x0(%rax,%rax,1)
```
takes 6 bytes.

someone point out that, maybe integer execution unit and float-point unit shares on instruction fetch, branch predictor, decode and dispatch unit.
Code layout and  alignment optimizations relative  to the shared resources can improve performance.

> the processor has the capability to memorize ONE jump instruction for every 16 bytes(32 bytes in newer processors)

## other refs
[amd-nopw-assembly-instruction](https://stackoverflow.com/questions/4798356/amd64-nopw-assembly-instruction)
