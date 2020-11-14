https://docs.oracle.com/cd/E19455-01/806-5257/6je9h033a/index.html

https://www.linuxjournal.com/article/3985

#### 分两大类
Signals are divided into two categories: traps and exceptions (synchronously generated signals) and interrupts (asynchronously generated signals).

#### traps
Traps (such as SIGILL, SIGFPE, SIGSEGV) result from something a thread does to itself, such as dividing by zero or explicitly sending itself a signal.
A trap is handled only by the thread that caused it. Several threads in a process can generate and handle the same type of trap simultaneously.

#### Interrupts
Interrupts (such as SIGINT and SIGIO) are asynchronous with any thread and result from some action outside the process.
Dealing with asynchronous signals is more complicated than dealing with synchronous signals.
An interrupt can be handled by any thread whose signal mask allows it. When more than one thread is able to receive the interrupt, only one is chosen.

#### Continuation Semantics
连续语义，就是当一个sig handler处理完之后，控制流从之前终端的地方恢复。异步信号常常采用这种方式方式，这也是很多编程语言异常处理的机制。

#### signal disposition 
都说信号的signal disposition是process-wide，那么什么是signal disposition。

#### process-wide
信号的处理是process-wide，man pthread_kill: if a signal handler is installed, the handler will be invoked in the thread thread, but if the disposition of the signal is "stop", "continue", or "terminate", this action will affect the whole process.
如果一个signal handler被设置为SIG_DFL或者 SIG_IGN，那么受到的信号会影响所有的线程。

#### 如何给特定线程发信号
这是给特定的线程发信号，与给进程发不一样，信号的处理只能是那个线程。
pthread_kill(3THR) is the thread analog of kill(2)--it sends a signal to a specific thread.This, of course, is different from sending a signal to a process. When a signal is sent to a process, the signal can be handled by any thread in the process. A signal sent by pthread_kill() can be handled only by the specified thread.

#### kill命令发给指定线程的信号也会发给线程组
man kill: In this case the kill behavior is not changed and the signal is also delivered to the thread group rather than to the specified thread.

#### 只有两种信号是不能catch的
SIGKILL / SIGSTOP

#### TSTP信号可以catch
TSTP等信号可以被捕捉，但是默认情况下，也是会让进程中所有的线程暂停。

#### KILL信号
发往进程中一个线程的KILL信号会导致整个进程终止，STOP信号会让进程中的所有线程暂停。因为信号会发送给 thread group。
