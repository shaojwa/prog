其实，因为系统计时器的原因，就算是调用纳秒级的接口clock_nanosleep，其实也没法真的达到那样的精度。
## sleep
## usleep
## nanosleep
相比sleep和usleep，nanosleep有更高的进度。
#### 这个接口的问题
(1)如果要求的时间间隔不是底层时钟的整数倍，那么interval就会向上取整。
(2)就算sleep完成，到CPU空闲可以执行调用函数，还是有一段时间的延迟。
(3)nanosleep如果用相对时间间隔，而且总是因为信号打断而重复启动的话，是会有问题的，因为中断和重启之间的时间并没有算进时间流逝。
(4)nanosleep针对CLOCK_REALTIME进行计时，但是linux是用CLOCK_MONOTONIC计时，这也许不是个问题，因为POSIX.1指定说clock_settime不能。

## clock_nanosleep
相比nanosleep，clock_nanosleep提供更多的clock_id和flag可选，可以指定绝对时间睡眠，这能很好解决nanosleep的一个问题。

## select
如果要考虑对于较早的unix系统的可移植性，那么select可能是很好的办法，但是这种场景现在越来越少。
之所以用select是因为sleep睡眠的时间粒度太大，而usleep又并不是在每个系统上都有，加上nanosleep并没有实现。
如果要对现在的程序编程，用nanosleep足够好，再不行用clock_nanosleep，所以用select的场景越来越少。
