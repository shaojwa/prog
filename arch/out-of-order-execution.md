《Computer Architecture out of order execution》 By Yoav Etsion ppt 64 pages

#### 为什么需要超标量（Superscalar）
因为需要速度，The need for speed

#### CPU运行时间计算方式
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

#### 什么是commit一条指令
commit an instruction

#### 乱序的优点
1. 指令集的并发 2. 隐藏延时

#### 乱序的缺点
硬件上的复杂度增加

#### 编译器能做一些乱序的工作么？
1. 以一种非常受限的方式可以
1. 编译器缺少运行时的信息，比如条件分支检测，变量值，缓存命中情况等。

ppt20
