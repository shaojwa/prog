#### done
1. 线程有创建它的父线程么？(done） 没有，ppid只显示父进程的pid 。
1. 进程的状态和它的线程的状态什么关系？(done) 没有，进程的状态就是进程中主线程的状态。
1. 快排实现一下(done)
1. atop中的slab内存了解一下(done)

#### todo

```
有没有更好的更实时的计算框架？（专访黄东旭）
两条路线，一条学术路线去扎实的做理论。另一条系统架构的路线，包括分布式存储和计算框架。（专访黄东旭）
另外一些比较偏实际的就是积极的参与开源社区，而且要和社区的人主动沟通起来。（专访黄东旭）
还有一点是好好学英语，这个非常重要，非常重要，非常重要！（专访黄东旭）
现在很火的 Hadoop 是 Google 02 ~ 06 年的几篇论文；
很火的容器技术的核心 cgroup 其实好多年前就已经进入了 linux 内核

同步信号和异步信号需要学习
线程 alternate signal stack 是什么？
为什么build可执行文件的时候才会检查函数的实现？
understanding the python gil
c++中的右值引用是怎么回事？

什么是Trie数，跳表。

20200806
如果程序启动时，各个模块有初始化依赖，就会涉及到先后顺序的问题，此时怎么做，都先用默认构造函数构造，然后调用初始化接口来做么？

20200728
Linux Kernel中AEP的现状和发展

20200714
pthread_spin_lock了解一下
https://docs.oracle.com/cd/E19253-01/816-5137/ggecq/index.html
paire vs struct-with-2-fields
https://stackoverflow.com/questions/2236182/what-is-the-difference-between-using-a-struct-with-two-fields-and-a-pair
```

20200710 flock 了解一下 
```
https://stackoverflow.com/questions/22486651/why-does-flock-use-a-descriptor-or-file
/usr/src/kernel4.4.0/Documentation/filesystems/locks.txt lock相关东西了解一下
```
```
Algorithm::Diff::sdiff() 算法了解
```
20200706
```
lockdep机制： /usr/src/kernel4.4.0/Documentation/locking/lockdep-design.txt
单例中资源的释放
```

```
菱形继承
WHR算法
何解决C代码中的double直接用等号比较问题
为什么二进制文件运行后允许删除但不允许覆盖
std::map的操作线程安全么？
微服务化架构设计了解一下
kdump了解一下：https://www.ibm.com/developerworks/cn/linux/l-cn-kdump1/index.html
SLUB 了解一下：https://www.ibm.com/developerworks/cn/linux/l-cn-slub/index.html
oom和oops机制了解一下：oom是内存不足，杀死进程的机制。 oops是节点崩溃重启生成vmcore的机制
cond_wait占用时间片么
```

####
Your GCC is too old. Please run following command to add DTS to your environment:
scl enable devtoolset-8 bash
Or add following line to the end of ~/.bashrc to add it permanently:
source scl_source enable devtoolset-8


#### O_PATH 参数是什么作用
1. open的时候有O_NOFOLLOW标记时，如果文件存在且是软链接，那么就返回失败。
1. 因为follow的时候就可能循环，软链接指向另外一个软链接。
1. 在linux下，如果O_NOFOLLOW的同时，如果有O_PATH时，并不会直接返回ELOOP，而是

那么O_PATH的作用是什么，两个目的（具体man一下open）：
1. 就是用来判断文件系统目录树上的某个位置是否存在。
1. 就是后续操作只是fd-level的操作，文件本身并没有打开，所以read，write，fchmod，fchown都会出错。

```
看一下ld的man手册
当进程文件删除之后，gdb挂载之后，为什么无法查看线程？
kill -kill 一个线程后为什么会把这个线程所在的进程中的所有线程杀掉？

task需要TASK_UNINTERRUPTABLE状态的原因
IO 时为什么处理信号非常困难
semaphore和mutex的区别（https://www.zhihu.com/question/47704079）
fork出来的子进程不能继承的资源到底是什么
pthread_cond_wait 为什么需要传递 mutex 参数？(https://www.zhihu.com/question/24116967)
Goodbye semaphores?（https://lwn.net/Articles/166195/）
https://stackoverflow.com/questions/4764945/difference-between-completion-variables-and-semaphores
c++ 的线程库以及同步库提供的接口和pthread接口的对应关系是什么？
linux存在强制锁（mandatory lock）和劝告锁（advisory lock），使用场景是什么？
xfs 文件系统写数据有journal么？
进程以及线程对不同信号的处理方式？
linux 内核中的三个 tcp keepalive参数是什么含义？
对目录调用 stat 系统调用时的返回值是什么意思？
sync，syncfs，fsync，fdatasync 等系统调用的区别和注意点？
lock_gettime() 接口中，CLOCK_REALTIME and CLOCK_MONOTONIC 区别以及适用场景？
正常TCP会话会保持多久？
TCP/IP重传超时RTO是什么意思？
优先级倒置是什么意思？
fork创建的子进程不会继承父进程挂起的信号，而exec创建的进程会继承父进程挂起的信号，为什么？
进程中的信号相关配置存储在哪里？
chroot 的适用场景是什么？
select微秒级精读是什么意思？
poll毫秒精度是什么意思？
pselect/ppoll纳秒级精但毫秒级已经不可靠
深入linux PAM体系结构    
EINTER 系统调用被中断    
ctrl+\终止前台进程组中进程并产生core
linux 系统编程p55
原生编程规范 是什么意思？
iopath结合图理解

// std
std::unordered_map;
std::unordered_multimap;
std::hash (std::bitset)
move也会抛出异常，所以不是所有的类型都是movable

// acm
信心上限树是什么(UCT) 是什么东西？
1234b2有其他算法需要了解下
红黑树实现
https://chortle.ccsu.edu/AssemblyTutorial/   
http://kerneltrap.org/node/517

5.5.4 Thread-Specific Breakpoints
https://sourceware.org/gdb/onlinedocs/gdb/Non_002dStop-Mode.html
https://sourceware.org/gdb/onlinedocs/gdb/Asynchronous-and-non_002dstop-modes.html
https://stackoverflow.com/questions/19181834/what-is-the-concept-of-vruntime-in-cfs
```
