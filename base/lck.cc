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
    int i = 0;
    pthread_spinlock_t *spl = (pthread_spinlock_t*)ptr;

    printf("tid %lu\n", (unsigned long)gettid());
    while (true) {
        pthread_spin_lock(spl);
        printf("get_spinlock, tid %lu\n", (unsigned long)gettid());
        sleep(10);
        pthread_spin_unlock(spl);
        sleep(1);
        if (++i == 10) {
            return NULL;
        }
    }
}


// check the address of the pthread_spin_lock
int probe_spinlock_stack()
{
    pthread_t thr1, thr2;
    pthread_spinlock_t spl;

    printf("pthread_spin_init\n");
    pthread_spin_init(&spl, 0);

    printf("routine: %p, &routine: %p\n", routine, &routine);
    pthread_create(&thr1, nullptr, routine, (void *)&spl);
    pthread_create(&thr2, NULL, routine, (void *)&spl);

    pthread_join(thr1, NULL);
    pthread_join(thr2, NULL);

    pthread_spin_destroy(&spl);
    return 0;
}

