20210205(p1-19)
## Chapter 1. Introduction
#### Welcome to Programming
1. poetry/convey/succinct/pass-over
1. With a program, you build your own world with your own rules.
1. The point is that programs are meant to be read by people, not just computers. 
1. Your goal is to solve the problem at hand, doing so with balance and taste.
1. I will take you through the difficult issues because that is the only way to move on to masterful programming.
1. it is sometimes best to take it by faith and come back to it later. 
```
Many of the questions don’t have right or wrong answers, but that doesn’t mean
they are unimportant. Learning the issues involved in programming, learning how
to research answers, and learning how to look ahead are all a major part of a
programmer’s work.
```

####  Your tools
1. Keyboard -> Kernel -> Windowing system -> Application program
1. Machine Language / Assembly Language / High-Level Language
1. Your understanding of how programming and computers work will put you a step ahead.

## Chapter 2. Computer Architecture
1. You need to first understand how a computer interprets programs. 
1. Modern computer architecture is based off of an architecture called the Von Neumann architecture.
1. The architecture divides the computer up into two main parts - the CPU and the memory. 

#### Structure of Computer Memory
1. but you can only store a single number in a computer memory storage location.
1. It is because it is simple to implement.
```
In addition to all of this, the Von Neumann architecture specifies that not only
computer data should live in memory, but the programs that control the computer’s
operation should live there, too. In fact, in a computer, there is no difference
between a program and a program’s data except how it is used by the computer.
They are both stored and accessed the same way.
```
#### The CPU
1. The CPU reads in instructions from memory one at a time and executes them. This s known as the fetch-execute cycle. 

The CPU contains the following elements to accomplish this:
- Program Counter
- Instruction Decoder
- Data bus
- General-purpose registers
- Arithmetic and logic unit

1. There are two kinds of registers - general registers and special-purpose registers. 
1. Processors have advanced quite a bit in recent years, and are now much more complex. 

it is complicated by the use of cache hierarchies, superscalar processors, pipelining, branch prediction,
out-of-order execution, microcode translation, coprocessors, and other optimizations. 
```
#### Some Terms
1. Addresses which are stored in memory are also called pointers.

#### Interpreting Memory
1. The point is, the computer will do exactly what you tell it, no matter how little sense it makes.

#### Data Accessing Methods
1. immediate mode = con
1. register addressing mode = reg
1. direct addressing mode = [addr]
1. indexed addressing mode = [addr + reg]
1. indirect addressing mode = [reg]
1. base pointer addressing mode = [reg + con]
