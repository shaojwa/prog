如果一个线程，一直在获取spinlock而获取不到，那么/proc/<pid>/sched/中的nr_switche会一直增长。
表明这个线程一直在消耗cpu，而且都是被迫让出cpu，总是把时间片用完。
因为nr_involuntary_switches会一直增长，表明这个线程被迫让出（involuntary）。
```
[wsh@li984-80 ~]$ cat /proc/1750453/sched | grep switches
nr_switches                                  :                 2811
nr_voluntary_switches                        :                    0
nr_involuntary_switches                      :                 2811
```
而如果一个线程是sleep的，那么nr_switches是不会增长的，也就是说这个线程并不消耗cpu。测试代码如下：
```
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>
#include <sys/time.h>
#include <list>
using namespace std;

static pid_t gettid() {
    return syscall( __NR_gettid );
}

void *routine(void *ptr)
{
  pthread_spinlock_t *spl = (pthread_spinlock_t*)ptr;
  printf("tid %lu\n", (unsigned long)gettid());
  pthread_spin_lock(spl);
  printf("get_spinlock, tid %lu\n", (unsigned long)gettid());
  sleep(1000);
  pthread_spin_unlock(spl);
  return NULL;
}


// check the address of the pthread_spin_lock
int main()
{
    pthread_t thr1, thr2;
    pthread_spinlock_t spl;

    printf("main thread %ld\n", (unsigned long)gettid());
    printf("pthread_spin_init\n");
    pthread_spin_init(&spl, 0);

    pthread_create(&thr1, nullptr, routine, (void *)&spl);
    pthread_create(&thr2, NULL, routine, (void *)&spl);

    pthread_join(thr1, NULL);
    pthread_join(thr2, NULL);

    pthread_spin_destroy(&spl);
    return 0;
}
```
