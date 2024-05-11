linux环境下，获取线程tid的方式是调用系统调用`syscall(SYS_gettid)`，编译的时候，如果没有` #ifdef __linux__`，就会返回`-ENOSYS`。
表示`Function not implemented`
