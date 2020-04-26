#### 微服务化架构设计

#### kdump

https://www.ibm.com/developerworks/cn/linux/l-cn-kdump1/index.html

#### SLUB

https://www.ibm.com/developerworks/cn/linux/l-cn-slub/index.html

## oom和oops机制

oom是内存不足，杀死进程的机制。 oops是节点崩溃重启生成vmcore的机制

#### cond_wait占用时间片么
#### O_PATH 参数是什么作用
1. open的时候有O_NOFOLLOW标记时，如果文件存在且是软链接，那么就返回失败。
1. 因为follow的时候就可能循环，软链接指向另外一个软链接。
1. 在linux下，如果O_NOFOLLOW的同时，如果有O_PATH时，并不会直接返回ELOOP，而是

那么O_PATH的作用是什么，两个目的（具体man一下open）：
1. 就是用来判断文件系统目录树上的某个位置是否存在。
1. 就是后续操作只是fd-level的操作，文件本身并没有打开，所以read，write，fchmod，fchown都会出错。
