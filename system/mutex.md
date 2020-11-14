#### 两个参考
(1) https://www.kernel.org/doc/html/latest/locking/mutex-design.html  
(2) https://lwn.net/Articles/164802/  

#### 什么是mutex
只是一种特定的锁原语（locking primitive），来强制对内存访问的串行化。这不这一种sleep lock，功能和binary semaphores非常类似。

#### 什么时候引入
2006年，作为binary semaphores的替代者引入。

#### 为什么引入mutex
mutex的引入在lwn上也有一些[讨论](https://lwn.net/Articles/166195/)，一开始社区觉得应该集中注意力在解决现在现有的semophore问题的解决，而不是引入一种新的互斥机制。
据说，原先没有mutex的时候，90%的用户用semophore来实现mutex。后来mingo大神说引入mutex有很多好处，他列了以下好处：
（1）mutex结构体占用空间更小。但是后来随着spin-mutex的新能优化，其实mutex的结构大小已经比semophore大，所以这个好处已经不存在。
（2）mutex有更快的速度和更低的cpu消耗。据说主要是因为mutex在slow-path中会用spin_lock替换sleep。

据说，理论上，为了获得锁而进行的spin，其时间长短不应该超过两次进程切换的时间开销，否则此处优化将没有意义。

其实内核文档(Documentation/mutex-design.txt)也非常值得一读。

#### mutex 的几个性质
mutex有很重要的一点是，某个线程lock，就得由那个线程unlock。

#### 什么时候用mutex
除非严格的mutex语义不适用，或者临界去不想通过锁去共享，一般都应该选择mutex而不是其他锁原语。

#### mutex 的实现
(1) 有一个包含三种状态的原子计数器，根据计数器的不同状态，有三种方式可以获取lock，fastpath/midpath/slowpath。

#### mutex_lock() 和 pthread_mutex_lock()
mutex_lock是内核接口，只能在内核中用。而pthread_mutex_lock()是用户态接口。

#### 和semaphore的区别
使用场景不同，mutex解决的是某个资源只能让一个线程访问。semaphore是控制资源的产生和消费，让多个线程可以配合，但并不是为让资源独占使用。

#### mutex中的fast-path和slow-path
其实这是mutex和semophore都有的场景，fast-path就是当前代码直接获得mutex（或sem），slow path就是当前代码无法获得，需要等待。
