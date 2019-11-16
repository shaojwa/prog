#### socket
主板上插CPU的槽，几个插槽就是有几路。
#### core
每一路上有CORE的数目，就是几核。
#### thread
每一个核里的硬件显成熟。要是用的是超线程，那么一般默认的就是2个硬件线程数，
#### cpu
以上几个数量相乘法就是一般我们说或的多少个CPU。

可以通过lscpu命令来查看这些信息：

    CPU(s):                12
    Thread(s) per core:    2
    Core(s) per socket:    6
    Socket(s):             1


#### SMT

是core 里的概念，一个核中物理thread之间的并发，intel的 hyper-threading 就是two-thread SMT。
