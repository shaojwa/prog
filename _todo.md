1. 有没有更好的更实时的计算框架？（专访黄东旭）
1. 两条路线，一条学术路线去扎实的做理论。另一条系统架构的路线，包括分布式存储和计算框架。（专访黄东旭）
1. 另外一些比较偏实际的就是积极的参与开源社区，而且要和社区的人主动沟通起来。（专访黄东旭）
1. 还有一点是好好学英语，这个非常重要，非常重要，非常重要！（专访黄东旭）
1. 现在很火的 Hadoop 是 Google 02 ~ 06 年的几篇论文；
1. 很火的容器技术的核心 cgroup 其实好多年前就已经进入了 linux 内核.
1. https://www.52cs.com/archives/story/前辈之路
1. decode接口有没有针对char指针的输出进行处理？

1. lockdep机制： /usr/src/kernel4.4.0/Documentation/locking/lockdep-design.txt
1. 单例中资源的释放
1. 同步信号和异步信号需要学习
1. 线程 alternate signal stack 是什么？
1. 为什么build可执行文件的时候才会检查函数的实现？
1. understanding the python gil
1. c++中的右值引用是怎么回事？
1. 什么是Trie数，跳表。

1. 想用一套框架来处理不同的batch和task，那么自然，接口中都是用的基类指针。
但是派生类的构造是不是只能独立于框架接口，不同的batch用batcher的工厂模式创建么？
batch中的不同task又怎么在框架内构造？不同的派生task，派生batch必然需要有自己的特定接口吧
1. libc里已经有strtol()，但是ceph中又实现 strict_strtol() 系列函数将string转为整数，为什么要新实现一个？
``` 
int level = (int) strict_strtol(levelstr.c_str(), 10, &err);
```
1. 试试用指针的引用。
1. iterator的命名，是it_map还是map_it。
1. 比较时常量宏写等号左边还是右边。
1. ceph中如果嵌套比较深，会不会倾向用if把特例先continue掉，这样减少嵌套深度。
1. 想一个string 到 int 的hash比较简单的算法。

1. 接口函数和工作函数什么时候分离？工作函数被调用较多，或者接口函数需要处理锁操作的时候。
1. 模块处于STOPPED状态，无法处理请求，接口该如何返回错误码？

1. 一个指针数组空间的释放怎么实现最好？
1. 保护状态的小锁是否有必要？比如rcache_state
1. 模块对外接口中，状态判断没有必要么？
1. release 掉析构，还是析构中掉release？ 应该是析构中掉release，析构掉再执行release中this就不可用。
1. 一个外部接口调用另外一个外部接口，两个接口都有需要加锁的场景，怎么设计？ `if(mutex.is_locked_by_me()) { mutex.unlock(); } `
1. 模块状态机需要分NONE，INIT，ACTIVE等多个状态么？是否尽可能简单比较好？
1. 先设置状态还是，等所有操作之后再设置状态，比如STOP模块的时候？？

20200806
如果程序启动时，各个模块有初始化依赖，就会涉及到先后顺序的问题，此时怎么做，都先用默认构造函数构造，然后调用初始化接口来做么？

20200728
Linux Kernel中AEP的现状和发展

20200714
pthread_spin_lock了解一下
https://docs.oracle.com/cd/E19253-01/816-5137/ggecq/index.html
paire vs struct-with-2-fields
https://stackoverflow.com/questions/2236182/what-is-the-difference-between-using-a-struct-with-two-fields-and-a-pair

1. 20200710 flock https://stackoverflow.com/questions/22486651/why-does-flock-use-a-descriptor-or-file
1. locks 了解一下 /usr/src/kernel4.4.0/Documentation/filesystems/locks.txt lock
1. Algorithm::Diff::sdiff() 算法了解

20200706

1. 菱形继承
1. WHR算法
1. 何解决C代码中的double直接用等号比较问题
1. 为什么二进制文件运行后允许删除但不允许覆盖
1. std::map的操作线程安全么？
1. 微服务化架构设计了解一下
1. kdump了解一下：https://www.ibm.com/developerworks/cn/linux/l-cn-kdump1/index.html
1. SLUB 了解一下：https://www.ibm.com/developerworks/cn/linux/l-cn-slub/index.html
1. oom和oops机制了解一下：oom是内存不足，杀死进程的机制。 oops是节点崩溃重启生成vmcore的机制
1. cond_wait占用时间片么
1.  O_PATH 参数是什么作用
1. open的时候有O_NOFOLLOW标记时，如果文件存在且是软链接，那么就返回失败。
1. 因为follow的时候就可能循环，软链接指向另外一个软链接。
1. 在linux下，如果O_NOFOLLOW的同时，如果有O_PATH时，并不会直接返回ELOOP，而是
1. 那么O_PATH的作用是什么，两个目的（具体man一下open）：
1. 就是用来判断文件系统目录树上的某个位置是否存在。
1. 就是后续操作只是fd-level的操作，文件本身并没有打开，所以read，write，fchmod，fchown都会出错。
1. 看一下ld的man手册
1. 当进程文件删除之后，gdb挂载之后，为什么无法查看线程？
1. kill -kill 一个线程后为什么会把这个线程所在的进程中的所有线程杀掉？
1. task需要TASK_UNINTERRUPTABLE状态的原因
1. IO 时为什么处理信号非常困难
1. semaphore和mutex的区别（https://www.zhihu.com/question/47704079）
1. fork出来的子进程不能继承的资源到底是什么
1. pthread_cond_wait 为什么需要传递 mutex 参数？(https://www.zhihu.com/question/24116967)
1. Goodbye semaphores?（https://lwn.net/Articles/166195/）
1. https://stackoverflow.com/questions/4764945/difference-between-completion-variables-and-semaphores
1. c++ 的线程库以及同步库提供的接口和pthread接口的对应关系是什么？
1. linux存在强制锁（mandatory lock）和劝告锁（advisory lock），使用场景是什么？
1. xfs 文件系统写数据有journal么？
1. 进程以及线程对不同信号的处理方式？
1. linux 内核中的三个 tcp keepalive参数是什么含义？
1. 对目录调用 stat 系统调用时的返回值是什么意思？
1. sync，syncfs，fsync，fdatasync 等系统调用的区别和注意点？
1. lock_gettime() 接口中，CLOCK_REALTIME and CLOCK_MONOTONIC 区别以及适用场景？
1. 正常TCP会话会保持多久？
1. TCP/IP重传超时RTO是什么意思？
1. 优先级倒置是什么意思？
1. fork创建的子进程不会继承父进程挂起的信号，而exec创建的进程会继承父进程挂起的信号，为什么？
1. 进程中的信号相关配置存储在哪里？
1. chroot 的适用场景是什么？
1. select微秒级精读是什么意思？
1. poll毫秒精度是什么意思？
1. pselect/ppoll纳秒级精但毫秒级已经不可靠
1. 深入linux PAM体系结构    
1. EINTER 系统调用被中断    
1. ctrl+\终止前台进程组中进程并产生core
1. linux 系统编程p55
1. 原生编程规范 是什么意思？
1. iopath结合图理解

// std
std::unordered_map;
std::unordered_multimap;
std::hash (std::bitset)
move也会抛出异常，所以不是所有的类型都是movable

// acm
1. 信心上限树是什么(UCT) 是什么东西？
1. 1234b2有其他算法需要了解下
1. 红黑树实现：https://chortle.ccsu.edu/AssemblyTutorial/   http://kerneltrap.org/node/517

5.5.4 Thread-Specific Breakpoints
https://sourceware.org/gdb/onlinedocs/gdb/Non_002dStop-Mode.html
https://sourceware.org/gdb/onlinedocs/gdb/Asynchronous-and-non_002dstop-modes.html
https://stackoverflow.com/questions/19181834/what-is-the-concept-of-vruntime-in-cfs
