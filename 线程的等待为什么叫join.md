#### 线程的等待为什么叫join

join本意是加入，对应的detach叫分离。
glibc中的thread_join调用lll_wait_tid 实现
