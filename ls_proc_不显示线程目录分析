之前了解 proc文件系统，知道ls /proc 可以看到所有以系统中进程作为名字的目录。
后来发现，其实 /proc/<线程号>也是可以cd进去的，只是ls /proc的时候没有显示（即只显示进程目录，不显示线程目录）。
其实cd /proc/<线程号>可以访问没什么奇怪的。毕竟在系统看来，进程线程都是任务，都用sched.h中的task_struct结构来表示。
只是好奇内核是怎么过滤的，是不是通过线程的pid是否等于进程id来判断。
查看了下代码，内核是通过/fs/proc/目录下的base.c文件中的proc_pid_readdir() 接口来实现ls /proc 对进程目录的显示，
该接口调用的关联接口是next_tgid()，net_tgid()下又有一个比较关键的判断：


```

if (!iter.task || !has_group_leader_pid(iter.task)) {

			iter.tgid += 1;

			goto retry;

}

```

查看has_group_leader_pid(iter.task)的代码就知道原因：

```

static inline bool has_group_leader_pid(struct task_struct *p)

{

	return task_pid(p) == task_tgid(p);

}

```

tgid就是thread group id的意思，就是通过看task中的tgid（线程所在的进程id）是否等于pid（线程的id号）。
