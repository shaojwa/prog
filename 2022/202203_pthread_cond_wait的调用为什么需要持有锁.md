为了让wait的等待校验过程串行化？我觉得里有两个原因。

#### 为了和cond_var相关的数据做好同步
mutex的持有锁，意味着，别的流程不能持有锁，意味着这个锁相关的资源只有一个thread在访问。
所以，pthread_cond_wait池有所，有利于pthread_cond_wait在校验是否满足以及满足之后，对数据操作的互斥。

#### 要是没有什么关联数据呢？
为了让signal和wait互斥？不是的。pthread_cond_wait释放mutex和进入block状态是原子的。
但是，注意，并不是说，通过mutex来保证原子，而是mutex的释放和进入block状态是原子的。所以，如果一个thread 调用signal，前先持有锁。
那么意味着，持有到锁并signal的时候，原先wait的线程已经已经block。

#### 为什么pthread_cond_signal
如果是这样我，为什么signal不需要传入mutex？因为有的情况下，确实不需要，而有的情况也确实需要。
查看man页面，我们知道，如果predictable scheduling behavior is  required，那么mutex需要被调用pthread_cond_signal的线程locked。
那什么是predictable scheduling behavior，意思就是如果调度行为可预测是需要的，那么我们也就需要在调pthread_cond_signal的时候持有锁。
因为这样就能保证signal的时候和wait的时候不会同时进行。
