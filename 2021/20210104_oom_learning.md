
#### 背景
task申请内存的时候用的是虚拟内存，在64为机子上来说，这几乎是无限的，那么在物理内存有限的情况下，什么时候会出现OOM？

#### OOM发生在什么时间点， 是malloc的时候，还是access的时候？
网上资料显示，用户空间的内存都是读写时分配，所以malloc的时候不会出错，而是在内核handle_mm_fault()函数中做缺页处理。

#### OOM的根源
linux中有overcommit这么一种机制，访问这个`http://linuxperf.com/?p=102`,个人理解OOM和overcommit算是一种trade-off。

#### linux的内存分配机制
Unix/Linux的内存分配策略是lazy的，申请的时候不会分配物理内存，只有在使用的时候才分配。

#### 参考
https://www.zhihu.com/question/21972130
