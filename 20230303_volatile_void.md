```
wshlock.cc:40:46: error: invalid conversion from ‘volatile void*’ to ‘void*’ [-fpermissive]
     pthread_create(&thr2, NULL, routine, &spl);
```
为什么局部变量spl是`volatile void *` 因为这里的spl是一个函数的局部变量，这个变量的地址是可能释放的。
而兴起的线程，是可能会放到这个地址的，如果要避免这个告警，可以把spl设置为new出来的地址。

```
extern int pthread_create (pthread_t *__restrict __newthread,
                           const pthread_attr_t *__restrict __attr,
                           void *(*__start_routine) (void *),
                           void *__restrict __arg) __THROWNL __nonnull ((1, 3));
```
只是把spl放置为static变量不能解决问题。
