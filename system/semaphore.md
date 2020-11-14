https://www.cnblogs.com/linengier/p/9399880.html

#### 使用的方式
有sem_post，sem_wail，semget，semctl，semop等一系列接口可以用，是libc对相应系统调用分封装。
https://dlonng.com/posts/semaphore
#### 查看信号量的命令
```
#### ipcs -s
```

#### 和 mutex的区别
#### POSIX 信号量与SYSTEM V信号量的比较
#### 信号量为什么需要锁？
信号量也是为了同步，同步是为了保证数据访问的串行，所以需要锁的配合，先持有信号量需要的锁，循环中的信号量Wait锁。
