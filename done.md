1. learning lockdep (/usr/src/kernel4.4.0/Documentation/locking/lockdep-design.txt)
1. 快排实现一下(done)
1. 关于post和pre接口的命名怎么写？一般post和pre在动词前，比如postfix，prefix。
1. 枚举型的必要性到底有多少？ ceph中似乎很少用，用的比较多的是定义宏，参数类型用int。
1. 等号比较常量一定要放左面么？ ceph代码没有这个要求，按照语义顺序来，一般常量放在等号右边。
1. int返回值是否为0怎么写(done)
1. 如何在构造map是初始化元素(done)
1. 构造函数参数名和成员同名怎么区分？参数以下划线结束，比如param_，参见 MDSRank::MDSRank。
1. 非公共成员函数怎么区别public成员函数？ 以下划线开始，比如_stop_local()，参见 class AsyncConnection。
1. new之后要不要校验返回值是否为null(done)
1. 类中成员是引用类型是否支持？当然支持，而且需要在构造函数中完成初始化。
1. 线程有创建它的父线程么？(done） 没有，ppid只显示父进程的pid 。
1. 进程的状态和它的线程的状态什么关系？(done) 进程的状态就是进程中主线程的状态，和其他线程没有关系。
1. atop中的slab内存了解一下(done)
1. Mutex中的Lock/Unlock是void类型，而ptherad_mutex_lock是有返回值的，怎么做这个一层屏蔽转换？(20201119)
1. 关于大括号的初始化语法(20201123)
1. 边界怎么说？ bound，比如复杂度的上界，下界一般用lower bound，upper bound。（20201123）
1. `scl enable devtoolset-8 bash`是什么用法？(20201123)
1. 什么是Trie树（20201123）
1. 什么是跳表（20201123）
1. iterator的命名，是it_map还是map_it。(20201124)
1. 比较时常量宏写等号左边还是右边。(20201124)
