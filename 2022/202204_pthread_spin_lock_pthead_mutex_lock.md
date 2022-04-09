#### ceph 中的 Spinlock
看了下代码实现，ceph定义了自己的ceph_spinlock_t类型，这个类型给根据 HAVE_PTHREAD_SPINLOCK这个宏的定义来决定是用
pthread_spinlock_t 还是pthread_mutex_t，那么一个自然的问题是，这两个有什么区别？

#### pthread_spinlock_t 和 pthread_mutex_lock的区别
很明确的一点是，`pthread_spin_lock(pthread_spinlock_t *lock)`的调用线程如果没有持有锁，这个接口是不会返回的。
而pthread_mutex_lock()接口也是这样的，那区别是什么？难道是一个会释放时间片，一个不会释放时间片？至少从man页面上是看不到区别的。
使用spin_lock，会不会释放时间片，其实就是不想进行上下文的切换，不想这个thread被换出后又等待scheduler器换入。我们用spin_lock就可以避免这种情况。
而mutex，会放弃当前的时间片，等待再次被调度到。

这里有一个讨论非常值得了解：https://www.alexonlinux.com/pthread-mutex-vs-pthread-spinlock/
