#### 20210303 p165-p174
System calls take a long time. They aren’t like functions, because the
processor has to switch modes. Your program isn’t allowed to map itself memory,
but the Linux kernel is. So, the processor has to switch into kernel mode, then
Linux maps the memory, and then switches back to user mode for your application
to continue running. This is also called a context switch. Context switches are
relatively slow on x86 processors. Generally, you should avoid calling the kernel
unless you really need to.

