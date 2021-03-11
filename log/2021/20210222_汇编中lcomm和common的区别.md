comm是declare一个symbol，注意，只是declare。 ld可见，在linking的之后自然会合并。如果没有以机构定义的symbol，那么ld机会申请未分配的空间。

lcomm不是全局申明，只是局部，而且一定会预留空间，也是未初始化的。ld不可见，地址在bss段中。
