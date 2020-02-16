#### mutex

pthread_mutex_unlock有很重要的一点是，那个线程lock，就得由那个线程unlock，否者会有EPERM错误。
就算是递归的mutex，也一样，一个thread可以将lock count 涨上去，但是不能由其他的thread降下来。只有count为0才可以被其他的thread得到。
所以，这是一个线程互斥访问资源的功能。

#### semaphore

semaphore 的本意是一个发送信号的系统，通过两面旗来完成，一个人通过挥动手臂来代表不同的含义。来源于火车站的信号灯，本身含有【通知】的含义。
知乎上有人说 semaphore 一个很重要的目的是为了调度线程，让产生资源的线程和消费资源的线程合乎逻辑得进行执行。

