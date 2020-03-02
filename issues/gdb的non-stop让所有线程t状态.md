在`.gdbinit`文件中开启`set non-stop on`之后，挂载进程，所有线程t状态：
```
(gdb) set target-async on
Cannot change this setting while the inferior is running.
(gdb) set non-stop on
Cannot change this setting while the inferior is running.
``
