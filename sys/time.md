#### 时间类型
（1）系统时间（2）进程时间

#### 时间数据结构的转变
（1）time_t 就是 long （2）timeval，time value in us （3）timespec，time_t + long。


#### 系统范围时钟 和 进程范围时钟
时钟可以是系统范围内的（system-wide）或者只是进程范围内的。

#### CLOCK_REALTIME 和 CLOCK_MONOTONIC
系统范围内包括两种，一种是实时时钟（墙上时钟）是CLOCK_REALTIME。另一种是CLOCK_MONOTONIC是一重单调时钟，不能设置，但是可以通过adjtime进行增加。
也就说他是单调递增的，只能增加不能减少。CLOCK_REALTIME 和 CLOCK_MONOTONIC 都是一种clockid_t。

#### 系统编程的推荐接口
用`clock_gettime()`
