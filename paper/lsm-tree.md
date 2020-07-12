## 参考
http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.44.2782&rep=rep1&type=pdf
https://zhuanlan.zhihu.com/p/38810568
https://juejin.im/post/5b1f69dee51d4506d25e31ea

存储领域，对于非结构化的数据（kv形式）是当前非常常见的存储形式。
而kv存储的实现机制中，常见的就是LSM-tree，比如LevelDB，RocksDB。
LSM-tree最早是1996年的一篇论文《The Log-Structured Merge-Tree (LSM-Tree)》

很多引擎都是采用Log-Structured Merge-Tree 结构来做kv存储，特点是写性能很好，读性能也不错。  
LSM-tree是一种对写进行优化的实现方式，核心自然是把随机写变成顺序写。因此它的缺陷就是写放大。
机械硬盘来说，顺序写和随机写的性能据说差1000倍，所以改成顺序写的价值是很大的。

#### 关于写放大
LSM-tree的关键指标是写放大，写分好几种，有立即写和延迟写，redo log肯定是立即写，日志需要马上落盘。
而后续的异步写包括数据刷盘以及LSM-tree的compact就是延迟写。

网上看到的写放大对于RocksDB来说有42倍，levelDB也有27倍。

写放大影响设备的使用设备，能耗，以及网络带宽，所以降低写放大是很重要的一个方面，特别是现在SSD在逐步普及。

#### 关于读放大

#### 关于空间放大

#### 关于日志

对于存储系统来说，日志几乎是不可避免的。

#### 数据的插入

有数据插入，先把kv写入LogFile，然后再把kv写入内存表memtable。同时达到一定的容量后，内存表会变成只读，写入磁盘变成SSTable。
找各种SSTable达到一定的数目，比如四个，就会另外分层，这样磁盘上就会有多个level。

#### level的Compaction
这种level多了之后，因为我们知道SSTable记录的是kv操作，那么某一个key就可能有多次操作位于不同的level中，这样两个level之间就有重叠。
所以，这时候就可以进行level之间的压缩，这叫做compact。


#### LevelDB 中的compaction压缩
