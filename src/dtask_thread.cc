#include <sys/syscall.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int get_tid() {
  return syscall(SYS_gettid);
}

static void *start_fn(void *arg)
{
  printf("thread %d start\n", get_tid());
  //if (!vfork()) {
  //  sleep(120);
  //}
  sleep(120);
  printf("thread %d returns\n", get_tid());
}

struct thread_t {
  void *(*fn)(void*);
  pthread_t id;
  int tid;
};

int main(int argc, char* argv[]) {
  int ret;
  thread_t th;
  th.fn = start_fn;
  printf("thread %d start\n", get_tid());
  ret = pthread_create(&th.id, NULL, th.fn, NULL);
  if (ret) {
    printf("ERROR: create thread failed: %d\n", ret);
    exit(0);
  }
  printf("OK: create thread done\n");
  if (!vfork()) {
    sleep(60);
    return;
  }
  ret = pthread_join(th.id, NULL);
  if (ret) {
    printf("ERROR: join thread failed: %d\n", ret);
    exit(0);
  }
  printf("OK: join thread done\n");
  printf("thread %d returns\n", get_tid());
  return 0;
}
