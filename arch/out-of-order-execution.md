1. 《Computer Architecture out of order execution》 By Yoav Etsion ppt 64 pages
1. https://www.cs.uaf.edu/2011/spring/cs641/proj1/vsanditi/
1. https://www.intel.com/content/dam/www/public/us/en/documents/manuals/64-ia-32-architectures-optimization-manual.pdf

#### simultaneously
A processor that executes the instructions one after the other, may use the resources inefficiently that leads to poor perfpormance of the processor.
To improve the performance of the processor this can be done in two ways. 
By executing different sub-steps of sequential instructions simultaneously or even executing the instructions entirely simultaneously.
Further improvement in the processor can achieved through out-of-order execution[2]. Out-of-order execution can be achieved by executing the instruction in an different from the original order they appear[1].

#### instruction cycles
1. retrieves program instruction from its memory
1. determines what action the instruction requires
1. carries out those actions

#### multiple execution units
In other words, processor that uses multiple execution units completes the processing of instructions in wrong order. 

#### first machine  to use oooe
The first machine to use out-of-order execution is CDC 6600(1964)，In 1966 IBM introduced Tomasula's algorithm which supports full out-of-order execution.

#### Tomasula's algorithm

#### In-order execution
In old processors, the processing of instruction is done in-order. The steps required for In-order processor are as follows:
1. The processor retrieves program instructions from its memory.
2. If the input operands are available in the register the instruction is sent to execution unit.
3. If the operand in unavailable during the clock cycle the processor will wait until they are available. This is because the operands are fetced from the memory and are unavailable, so the processor needs to wait until they are available during the current clock cycle.
4. Then the instruction is executed by the appropriate execution unit.
5. After the instruction is executed by the execution unit, it writes back to the register.[1]

#### in an order of availability of operands 
In out-of-order processor, the instructions are executed in an order of availability of operands The steps required for In-order processor are as follows:
1. The processor retrieves program instructions from its memory.
2. Instruction are sent to an instruction queue. Instruction queue is also called instruction buffer or reservation stations
3. Until the input operand is available the instruction waits in the queue. The instruction are allowed to leave the queue for the execution.Instruction doesn't need to wait in the queue until its turn. Whenever the operand is available the instruction will leave the queue or buffer for execution.
4. The instruction is sent to appropriate execution unit for execution.
5. Then the results are queued.
6. If all the older instructions have their results written back to register, then the current result is written back to the register file.
[1]

#### instruction queue
Instruction doesn't need to wait in the queue until its turn.

#### why Superscalar
The need for speed

#### CPU time
CPU Time = duration of clock cycle × CPI × IC

#### 指令五级处理过程
取指令阶段（IF），指令译码阶段（ID），指令执行阶段（EX），存储器访问阶段（MEM），寄存器回写阶段（WB）

#### 为什么不用更深的流水线
在一定的程度之后，添加更多的管道状态是没什么用的，因为control/data的风险在增加。只有当CPI为1时才不会有风险。

#### 接下去怎么做
（1）通过利用ILP（指令级的并发）来降低CPI。（2）更多的HW（hardware）

#### 超标量的问题
（1）只有相互独立的指令可以并行（2）相邻的指令常常并不独立。

#### 乱序执行
（1）基于数据流图（2）需要保持原有程序的语法。

#### commit an instruction
commit an instruction

#### 乱序的优点
1. 指令集的并发 2. 隐藏延时

#### 乱序的缺点
硬件上的复杂度增加

#### 编译器能做一些乱序的工作么？
1. 以一种非常受限的方式可以
1. 编译器缺少运行时的信息，比如条件分支检测，变量值，缓存命中情况等。
