```
#include <pthread.h>

int pthread_cond_timedwait(pthread_cond_t *restrict cond,
       pthread_mutex_t *restrict mutex,
       const struct timespec *restrict abstime);
int pthread_cond_wait(pthread_cond_t *restrict cond,
       pthread_mutex_t *restrict mutex);
```

#### type qualifier
https://en.cppreference.com/w/c/language/restrict

#### 目的
其实就是要求，只有一个指针指向一个对象，不能有多个指针指向同一个对象。
