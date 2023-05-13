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

pthread_spinlock_t gspl;
pthread_mutex_t gm;

void *routine(void *ptr)
{
  printf("tid %d, start\n", gettid());
  //pthread_mutex_lock(&gm);
  pthread_spin_lock(&gspl);
  printf("tid %d, got lock, gspl %d\n", gettid(), gspl);
  sleep(1);
  int i = 10;
  while(i--) {
    sleep(1);
    printf("tid %d, gspl %d\n", gettid(), gspl);
  }
  printf("tid %d, unlock\n", gettid());
  pthread_spin_unlock(&gspl);
  printf("tid %d, post unlock, gspl %d\n", gettid(), gspl);
  //pthread_mutex_unlock(&gm);
  return nullptr;
}


int probe_spinlock_stack()
{
    pthread_t th1;
    pthread_t th2;
    pthread_t th3;
    pthread_t th4;
    pthread_t th5;
    printf("pthread_spin_init\n");
    pthread_spin_init(&gspl, 0);
    pthread_mutex_init(&gm, 0);
    printf("tid %d, gspl %d\n", gettid(), gspl);
    pthread_create(&th1, nullptr, routine, nullptr);
    pthread_create(&th2, nullptr, routine, nullptr);
    pthread_create(&th3, nullptr, routine, nullptr);
    pthread_create(&th4, nullptr, routine, nullptr);
    pthread_create(&th5, nullptr, routine, nullptr);

    pthread_join(th1, nullptr);
    pthread_join(th2, nullptr);
    pthread_join(th3, nullptr);
    pthread_join(th4, nullptr);
    pthread_join(th5, nullptr);

    pthread_spin_destroy(&gspl);
    return 0;
}

