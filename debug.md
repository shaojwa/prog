

#### 系统调用号在什么头文件定义？
    
    asm/unistd_64.h:190:#define __NR_gettid 186
    bits/syscall.h:577:# define SYS_gettid __NR_gettid  


#### 查看内核配置 

sysctl下的很多配置的解释可以到[这里](https://www.kernel.org/doc/Documentation/sysctl) 找到。　　
sysctl和在proc下的操作sys是一致的，所以相比/proc/sys这么长的路径，还是用sysctl来得快。　　

#### 丢弃内核缓存 

非破坏性操作，并不会释放脏对象。官方文档已经说明，这不是一个控制内核各种缓存增长的方法。  
该操作会引起性能问题，因为他丢弃缓存对象，因此还有明显的IO以及CPU消耗来重新创建这些对象，特别是对象正在重度使用的时候。
1: 释放页缓存, 2:释放可回收的slab对象包括dentries和inodes，3：页缓存和slab对象

    vm.drop_caches = 3
    
#### 内核中的tcp连接保活参数

    tcp_keepalive_time: 最后一个数据包和第一次保活探测之间的时间间隔。
    tcp_keepalive_intvl: 包括探测之间报文之间的时间间隔。
    tcp_keepalive_probes: 连接被标记为dead时所需要的无返回探测报文个数。

#### 什么是slab

    slab是一种Linux内存分配算法。

#### watchdog_thresh是干什么的

    kernel.watchdog_thresh

用来控制hrtimer（高精度定时器）和NMI（不可屏蔽中断）的事件的频率。
进而也影响到softlockup 和 hardlockup的筏值，通常这个筏值是watchdog_thresh的两倍。

#### dirtytime_expire_seconds

都知道atime的改变只是文件访问引起的，但是这个inode却脏了。inode脏了是需要下刷inode到disk的。所以这个问题就有多种优化思路：  
noatime：直接干掉atime，让系统中的atime失效。  
reatime：ctime和mtime的时间晚于atime时才去更新atime。  
lazytime，控制inode下发的时间。  
后台bdi用来写回dirty inode，就是bdi_writeback->b_dirty，就看dirty 的inode什么时候放到这个队列。  
如果是i_size等关键inode属性改变，具体文件系统层会放到这个队列 ，如果是ctime等不关键属性，那么VFS层负责把inode放到这个队列中。  

#### gdb基本用法
搜索命令

    apropos 
    
远程调试

    gdbserver --attach :4444 <pid>
    gdb ceph-mds
    target remote 192.168.0.11:4444
    
断点

    save breakpoints <filename> // 保存断点
    break file.c:100 thread all
    
符号

    maint print symbol all.sym 
    info functions ptr::ptr
    set multiple-symbols // 多符号匹配时的行为
    
当前指令

    where
    p $rip
    
变量类型
    
    ptype
    wahtis
    
查看线程

    info thread
    thread <ID> 
    
查看类
    
    p *this
    p *(C_MaybeExpiredSegment *)0x7f17d08d8560
    
查看函数

    p C_MaybeExpiredSegment::complete
    
查看虚函数

    p C_MaybeExpiredSegment::finish时报错
    Cannot reference virtual member function "finish"
    
查看虚函数表

    info vtbl this
    
反汇编函数
    
    disass /m Server::handle_client_readdir
    
显示汇编代码

    set disassemble-next-line on
    intel格式	set disassembly-flavor intel
    
查看内存内容

    x $rbp-0x18
    
单行汇编执行

    si
    
网络相关

    set tcp auto-retry on
    
调度器

    set scheduler-locking off|on|step
    
信号捕捉

    info signals // 显示所有信号以及默认的gdb处理方式
	info handle  // =  info signals
	handle signal keywords
    
指定程序启动参数

    (gdb) file /opt/h3c/bin/ceph-mds
    (gdb) set args -f --cluster ceph --id mds0 --setuser ceph --setgroup ceph
    (gdb) run
