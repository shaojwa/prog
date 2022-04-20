#### 对共享数据的线程线程访问 要的两点保证
1. 对内存的而读写需要在内存中体现，而不是只是在寄存器中。
2. 对共享数据进行读写的代码相互之间不能乱序。

#### 什么时候会重排(reorder)
乱序并不是一个常常会发生的事，对变量有依赖的读写不会乱序。重排常常发生在不同变量的访问代码之间。因为看起来相互没有关系，就可能会发生重排。

[参考](https://stackoverflow.com/questions/2484980/why-is-volatile-not-considered-useful-in-multithreaded-c-or-c-programming)
