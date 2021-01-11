#### POSIX中提供的高级睡眠函数 clock_nanosleep

#### 为什么高级
相比nanpsleep来说，clock_sleep是高级的。
1.clock_nanosleep提供的时间有两种，一种是相对时间，也就是时间差值，一种是绝对时间。
1.clock_nanosleep的clock_id可以是实时时间，也可以是单调时间，
