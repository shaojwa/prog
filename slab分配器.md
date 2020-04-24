https://www.ibm.com/developerworks/cn/linux/l-linux-slab-allocator/index.html

## 内存管理的两个目标
1. 最小化管理内存所需要的时间。
1. 最小化管理内催所需要的空间（当可用内存尽可能大）。

内存管理实际上是一种关于权衡的零和游戏。

## 内存分配策略
1. 每个内存管理器一般使用了一种基于堆（内存块）的分配策略，当然还有一种策略是 buddy memory allocation。

基于堆的分配策略的根本问题是碎片（fragmentation），基于堆的内存分配通常有比较高的内存使用率。但是管理复杂度比较高，时间消耗较大。

## 搜索可用空间的算法
1. first-fit
1. best-fit
