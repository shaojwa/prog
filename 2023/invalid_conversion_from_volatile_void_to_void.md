```
wshlock.cc:40:46: error: invalid conversion from ‘volatile void*’ to ‘void*’ [-fpermissive]
     pthread_create(&thr2, NULL, routine, &spl);
```
because `volatile void *` is a local var? seems not:

```
pthread_spinlock_t gspl;
int test_spinlock_space()
{
    int i;
    pthread_t thr1, thr2;
    struct timeval tv1, tv2;
    const pthread_spinlock_t *pspl = malloc(sizeof(pthread_spinlock_t));

    
    printf("pthread_spin_init\n");
    pthread_spin_init(&gspl, 0);

    pthread_create(&thr1, NULL, routine, &gspl);
    pthread_create(&thr2, NULL, routine, &gspl);
    
    pthread_join(thr1, NULL);
    pthread_join(thr2, NULL);

    pthread_spin_destroy(&spl);
    return 0;
}
```
because the type `pthread_spinlock_t` is defined with keyword `volatile` like this:
```
/usr/include/bits/pthreadtypes.h:226:typedef volatile int pthread_spinlock_t;
```


