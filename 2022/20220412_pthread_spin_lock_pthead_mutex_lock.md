#### ceph 中的 Spinlock
看了下代码实现，ceph定义了自己的ceph_spinlock_t类型，这个类型给根据 HAVE_PTHREAD_SPINLOCK这个宏的定义来决定是用
pthread_spinlock_t 还是pthread_mutex_t，那么一个自然的问题是，这两个有什么区别？

#### pthread_spinlock_t 和 pthread_mutex_lock的区别
很明确的一点是，`pthread_spin_lock(pthread_spinlock_t *lock)`的调用线程如果没有持有锁，这个接口是不会返回的。
而pthread_mutex_lock()接口也是这样的，那区别是什么？难道是一个会释放时间片，一个不会释放时间片？至少从man页面上是看不到区别的。
使用spin_lock，会不会释放时间片，其实就是不想进行上下文的切换，不想这个thread被换出后又等待scheduler器换入。我们用spin_lock就可以避免这种情况。
而mutex，会放弃当前的时间片，等待再次被调度到。

这里有一个讨论非常值得了解：https://www.alexonlinux.com/pthread-mutex-vs-pthread-spinlock/

#### 什么时候用pthread_spinlock_t，什么时候用pthread_mutex_lock
简单来说，就是当你持有锁的时间很短时，用pthread_spinlock_t。
而我自己还想说一点就是，当不太容易发生获取不到锁的时候，用pthread_spinlock_t。
看起来这是一会事，但是是两个侧面，但是为什么是不太容易获取不到时，用spinlock？
那是因为spinlock能节省的是线程上下文的切换时间，如果很容易就能拿到锁，那么spin一下是划算的。

同样的，当时你spinlock的对lock的持有时间很短，意味着别人就不需要spin很久就能拿到。

#### spinlock的优点
```
On unlock, there is no need to check if other threads may be waiting for the lock and waking them up.
Unlocking is simply a single atomic write instruction.

Failure to immediately obtain the lock does not put your thread to sleep, 
so it may be able to obtain the lock with much lower latency as soon a it does become available.

There is no risk of cache pollution from entering kernelspace to sleep or wake other threads.
```
Point 1 will always stand, but point 2 and 3 are of somewhat diminished usefulness if you consider that good mutex implementations will probably spin a decent number of times before asking the kernel for help waiting.

https://stackoverflow.com/questions/6603404/when-is-pthread-spin-lock-the-right-thing-to-use-over-e-g-a-pthread-mutex
