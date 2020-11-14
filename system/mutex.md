https://www.kernel.org/doc/html/latest/locking/mutex-design.html

#### mutex引入
mutex的引入在lwn上也有一些[讨论](https://lwn.net/Articles/166195/)，一开始社区觉得应该集中注意力在解决现在现有的semophore问题的解决，而不是引入一种新的互斥机制。
据说，原先没有mutex的时候，90的的用户用semophore来实现mutex。其实内核文档(Documentation/mutex-design.txt)也非常值得一读。

#### mutex的几个性质

mutex有很重要的一点是，某个线程lock，就得由那个线程unlock。

#### 和semaphore的区别
使用场景不同，mutex解决的是某个资源只能让一个线程访问。semaphore是控制资源的产生和消费，让多个线程可以配合，但并不是为让资源独占使用。
