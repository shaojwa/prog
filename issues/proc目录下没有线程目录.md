之前了解`proc`文件系统，知道`ls /proc`可以看到所有以系统中进程作为名字的目录。
后来发现，其实`/proc/<线程号>`也是可以`cd`进去的，只是`ls /proc`的时候没有显示（即只显示进程目录，不显示线程目录）。
其实`cd /proc/<线程号>`可以访问没什么奇怪的。毕竟在系统看来，进程线程都是任务，都用`sched.h`中的`task_struct`结构来表示。只是好奇内核是怎么过滤的，是不是通过线程的pid是否等于线程组id（tgid）来判断。
查看了下代码，内核是通过`/fs/proc/`目录下的`base.c`文件中的`proc_pid_readdir()` 接口来实现`ls /proc`对进程目录的显示，该接口调用的关联接口是`next_tgid()`，`net_tgid()`下又有一个比较关键的判断：

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
另外task_struct结构找那个的两个字段：
```
struct task_struct {
  ...
  pid_t     pid;
  pid_t     tgid;
  ...
}
```
