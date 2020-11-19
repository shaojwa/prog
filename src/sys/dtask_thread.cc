#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int get_tid() {
  return syscall(SYS_gettid);
}

static void *start_fn(void *arg)
{
  cout << "thread start: " << get_tid() << endl;
  if (!vfork()) {
    sleep(120);
  }
  //sleep(120);
  cout << "thread returns: " << get_tid() << endl;
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
  cout << "thread start: " << get_tid() << endl;
  ret = pthread_create(&th.id, NULL, th.fn, NULL);
  if (ret) {
    cout << "ERROR: create thread failed: " << ret << endl;
    exit(0);
  }
  cout << "OK: create thread done" << endl;
  //if (!vfork()) {
  //  sleep(60);
  //  return 0;
  //}
  cout << "call pthred_join()" << endl;
  ret = pthread_join(th.id, NULL);
  if (ret) {
    cout << "ERROR: join thread failed: " << ret << endl;
    exit(0);
  }
  cout << "OK: join thread done" << endl;
  cout << "thread returns: " << get_tid() << endl;

  return 0;
}
