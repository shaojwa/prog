#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>

int gettid1() {
    return syscall(__NR_gettid);
}

int gettid2() {
  return syscall(SYS_gettid);
}

void* start_routine(void *param) {
  printf("thread start, tid: %d\n", gettid1());
  sleep(100);
  printf("thread return, tid: %d\n", gettid2());
}

int main(void) {
  pthread_t tid;
  printf("primary thread, tid: %d\n", gettid1());
  int ret = pthread_create(&tid, NULL, start_routine, NULL);
  if (0 == ret) {
    printf("create thread success, new thread tid: %lu\n", tid);
  } else {
    printf("create thread faile.\n");
  }
  int retval = 2;
  printf("primary thread return, tid: %d\n", gettid2());
  pthread_exit(&retval);
}
