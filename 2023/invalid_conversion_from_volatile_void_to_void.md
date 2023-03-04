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
```
problem recurrent
```
extern int pthread_create (pthread_t *__restrict __newthread,
                           const pthread_attr_t *__restrict __attr,
                           void *(*__start_routine) (void *),
                           void *__restrict __arg) __THROWNL __nonnull ((1, 3));
```
