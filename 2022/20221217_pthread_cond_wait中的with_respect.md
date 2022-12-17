pthread_cond_wait的man手册中有一句话：
```
These functions atomically release mutex and cause the calling thread to block on the condition variable cond; 
atomically here means "atomically with respect to access by another thread to the mutex and then the condition variable". 
```

这里的with repect到底是什么意思？查了下collins，发现这是个短语，一般用来礼貌得不认同别人的意见。表示我尊重但是不同意。
回到man手册中的说法，就是线程释放锁并进入block状态是原子的。整理的 with repect的含义还是很不好理解。
