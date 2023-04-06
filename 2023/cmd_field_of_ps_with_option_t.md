```
[root@node101 ~]# ps -p 1412406
    PID TTY          TIME CMD
1412406 pts/0    00:01:57 out

[root@node101 ~]# ps -Tp 1412406
    PID    SPID TTY          TIME CMD
1412406 1412406 pts/0    00:00:00 out
1412406 1412407 pts/0    00:01:02 out
1412406 1412408 pts/0    00:01:10 out
```

using `pthread_setname_np()` to change the name of the thread.
