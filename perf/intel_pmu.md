1. https://cloud.tencent.com/developer/article/1442444
1. https://www.intel.com/content/dam/www/public/us/en/documents/manuals/64-ia-32-architectures-optimization-manual.pdf

#### PMU
Performance Monitoring Unit, 用于统计系统中发生的特定硬件事件。比如：
1. 缓存未命中（Cache Miss）
1. 分支预测错误（Branch Misprediction）

从这些事件中可以计算出个高级指标：
1. 每指令周期数（CPI）
1. 缓存命中率

#### TMAM
自顶向下的微体系架构分析方法（Top-Down Microarchitecture Analysis Method, TMAM）

#### 概述
一般来说，CPU 流水线在概念上分为两部分，即前端（Front-end）和后端（Back-end）。Front-end 负责获取程序代码指令，并将其解码为一个或多个称为微操作（uOps）的底层硬件指令。
uOps 被分配给 Back-end 进行执行，Back-end 负责监控 uOp 的数据何时可用，并在可用的执行单元中执行 uOp。 uOp 执行的完成称为退役（Retirement）。
通常情况下，大多数 uOps 通过流水线正常执行然后退役，但有时候投机执行的 uOps 可能会在退役前被取消，例如在分支预测错误的情况下。流水线槽（pipeline slot）代表处理一个 uOp 所需的硬件资源。
这种自顶向下的分析框架的优点是一种结构化的方法，有选择地探索可能的性能瓶颈区域。带有权重的层次化节点，使得我们能够将分析的重点放在确实重要的问题上，同时无视那些不重要的问题。

#### 设计
