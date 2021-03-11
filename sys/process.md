#### 进程创建
clone，请留意 CLONE_THREAD 标记，用这个标记时，新创建的task会和calling process 在一个thread group中
(the child is placed in the same thread group as the calling process.
Thread groups were a feature added in Linux 2.4 to support the POSIX threads notion of a set of threads that share a single PID. ) 
Internally, this shared PID is the so-called thread group identifier (TGID) for the thread group.
如果没有这个flag，那么clone出来的task就会有一个自己的tgid， 这个tgid就是他自己的tid，这个进程也就是这个thread group的leader。

#### 进程等待 wait 和 waitpid

* wait是一个系统调用，其实，这是glibc的一个包装。一个最基本的函数，功能简单，即如果有子进程终止（不管是正常终止还是异常），都会立即返回。
如果没有一个子进程终止，则阻塞。看参数就可以发现，wait只有一个参数。返回值是终止的进程id。
wait如何做到等待指定的进程？只能wait一次，然后看看是不是我们等待的进程，如果不是，那么再调用一次wait。
wait会保存之前wait过的进程的信息，然后当wait某个进程时，会先比较已经保存的进程的退出信息列表中有没有，没有就wait一下。
所以，针对这种wait某一个特定的进程的需求，早期的unix支持的并不好，所以才有waitpid。

* waitpid比较起来就复杂很多，有很多参数可以控制，比如如果没有子进程终止也不会阻塞，还比如可以指定要等待的是哪个进程。
该接口增强在三个地方（1）可以指定特定进程。（2）可以不阻塞。（3）waitpid可以支持作业控制。
作业控制主要是停止（注意不是终止）和恢复，这两种情况，waitpid能获取到状态，而wait不行。对作业控制来说，这还是很重要的。
所以我们看到，shell中的作业控制（按下ctrl+z）时，shell在用户态的最后一个调用就是waitpid。


* wait3和wait4是从UNIX的BSD分支下来的，它的个功能比wait，waitpid多一点，就是可以知道终止进程的资源使用情况。
比如用户态CPU时间总量，内核态CPU时间总量，缺页次数，接收到的信号次数等。但是这两个函数已经不在标准的SUS中。 
所以当我们man wait3或者 man wait4时会告诉我们，These functions are obsolete; 
wait3 就是等待任一子进程，wait4就是可以指定某一进程。3、4表示的是参数个数。

#### 进程的状态

https://access.redhat.com/sites/default/files/attachments/processstates_20120831.pdf

A process is an instance of a computer program that is currently being executed.
Associated with a process is a variety of attributes  that extend or limit its ability to access resources on the computer

## UNDERSTANDING PROCESS TYPES

There are different types of processes in a Linux system. 
These types include user processes, daemon processes, and kernel processes
Changing kernel processes, however, may require recompiling the kernel.

## INTRODUCING SYSTEM STATES

p->state = TASK_RUNNING

## system calls

A CPU can execute either in kernel mode or in user mode. When a user initiates a process, the process
starts working in user mode. That user mode process does not have access to kernel data structures or
algorithms. Each CPU type provides special instructions to switch from user mode to kernel mode. If a userlevel process wants to access kernel data structures or algorithms, then it requests that information through
system calls that deal with the file subsystem or the process control subsystem. Examples of these system
calls include:

* File subsystem system calls: open(), close(), read(), write(), chmod(), and chown()
* Process control system calls: fork(), exec(), exit(), wait(), brk(), and signal()

## process states

#### Running
The process that is executing and using the CPU at a particular moment is called a running process.

#### Runnable State
When a process is in a Runnable state, it means it has all the resources it needs to run, except that the CPU
is not available. The Runnable state of this process is shown as R in ps output

Consider a example. A process is dealing with I/O, so it does not immediately need the CPU. When the
process finishes the I/O operation, a signal is generated to the CPU and the scheduler keeps that process in
the run queue (the list of ready-to-run processes maintained by the kernel). When the CPU is available, this
process will enter into Running state.

一个进程完成IO后回触发中断，中断处理程序会产生信号并告知CPU。调度器会将该进程的PID放进等待队列。

#### Sleeping

Consider a example. A process is dealing with I/O, so it does not immediately need the CPU. When the
process finishes the I/O operation, a signal is generated to the CPU and the scheduler keeps that process in
the run queue (the list of ready-to-run processes maintained by the kernel). When the CPU is available, this
process will enter into Running state.

#### Uninterruptible Sleep State

signals accumulated during the sleep are noticed when the process returns from the system call or trap. 

#### Terminate/Stop State

When a process
runs the exit system call, it releases its data structures, but it does not release its slot in the process table.
Instead, it sends a SIGCHLD signal to the parent. It is up to the parent process to release the child process
slot so that the parent can determine if the process exited successfully.

Between the time when the process terminates and the parent releases the child process, the child enters
into what is referred to as a Zombie state. A process can remain in a Zombie state if the parent process
should die before it has a chance to release the process slot of the child process. The reason you cannot kill
a Zombie process is that you cannot send a signal to the process to kill it as the process no longer exists.
