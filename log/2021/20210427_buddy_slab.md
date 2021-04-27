1. https://en.wikipedia.org/wiki/Buddy_memory_allocation
2. http://www.cs.jhu.edu/~yairamir/cs418/os5/sld016.htm

the buddy system was invented in 1963 by Harry Markowitz

## buddy system 的种类
有很多种，一分为二是最常见的一种。

## order
每一块连续的内存，都有一个order，从0到一个limit。order为n的块大小时2^n。

## buddy system 内存分配算法
Buddy system, 内存的分配算法，用不同的链表，同一个链表中的元素是一个连续的块空间。
比如，第10个链表中，每个元素块是连续的2^10个页，如果一页是4K，那么这个链表中的每个元素都是大小为4M的连续的空间。

## buddy 算法的要求
1，需要趋于后，0号和1号是伙伴，1号和0号不是伙伴。

## 伙伴算法的缺陷
1. buddy中的伙伴定义严格，并不是相邻的两个就是伙伴。比如0,1,2,3 4个块，1和2不是伙伴，不能合并，因为如果合并，0 就永远得不到合并。
1. buddy system 管理的内存是以页为单位的，所以管理的内存比较大，不适合小内存分配。

## stupid 分配器
