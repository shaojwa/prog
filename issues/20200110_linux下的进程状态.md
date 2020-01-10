TASK_INTERRUPTIBLE 可中断顺面的主要问题是，一旦内核被信号中断，就需要校验并返回给用户态-EINTR，并清理已经完成的工作。用户态也一样需要做相应的处理。


#### TASK_RUNNING
linux下，正在执行的task和就绪状态的task统一为一个状态 TASK_RUNNING。

#### TASK_INTERRUPTIBLE
是等待信号（其他进程发送）或者等待某个中断（比如IO完成触发的中断）

#### TASK_UNINTERRUPTIBLE
这里的 UNINTERRUPTIBLE 不是不响应硬件中断，而是不响应信号。task有的时候不允许切换去执行其他流程，必须等到执行后续流程。

参见《linux 内核异步中断浅析》、《神奇的vfork》

#### TASK_STOPPED or TASK_TRACED
两者很类似，都表示暂停下来。

#### TASK_DEAD
进程退出的过程中的状态。子进程通过SIGCHLD信号来通知父进程自己已经退出，如果是clone创建的子进程，通知信号可以设置。
