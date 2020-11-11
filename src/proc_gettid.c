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

int gettid() {
  return gettid1();
}

void* start_routine(void *param) {
  printf("new thread, start, tid %d\n", gettid());
  printf("new thread, sleep 10 secs\n");
  sleep(10);
  printf("new thread, return, tid %d\n", gettid());
  int retval = 1;
  pthread_exit(&retval);
}

int main(void) {
  pthread_t tid;
  printf("__NR_gettid %d\n", __NR_gettid);
  printf("SYS_gettid %d\n", SYS_gettid);
  printf("primary thread, tid %d\n", gettid());
  int ret = pthread_create(&tid, NULL, start_routine, NULL);
  if (0 == ret) {
    printf("primary thread, new thread tid %lu\n", tid);
  } else {
    printf("primary thread, create thread fail.\n");
  }
  void *pretval = NULL;
  pthread_join(tid, &pretval);
  printf("primary thread, pthread join returned\n");
  printf("primary thread, return, tid %d\n", gettid());
  pthread_exit(pretval);
}
