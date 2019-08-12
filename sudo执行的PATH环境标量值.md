#### 用sudo执行命令的过程

bash 先起进程执行sudo，sudo再起进程执行可执行文件。自己编译程序test打印PATH，就可以发现是否用sudo执行程序test会导致不一样的$PATH。而这个PATH和login shell中的用户是否为root也不是一回事。估计sudo自己设置了PATH等环境变量。
