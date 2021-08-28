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
  int n = *(int*)arg;
  int  max = 0;
  while (true) {
    sleep (n + 1);
  }
  cout << "thread returns: " << get_tid() << endl;
}

struct thread_t {
  void *(*fn)(void*);
  pthread_t id;
  int tid;
  int arg;
};

int main(int argc, char* argv[]) {
  int ret;
  int N = 4;
  thread_t ths[N];
  cout << "thread start: " << get_tid() << endl;
  for (int i = 0; i < N; i++) {
    ths[i].fn = start_fn;
    ths[i].arg = i;
    ret = pthread_create(&ths[i].id, NULL, ths[i].fn, (void *)&ths[i].arg);
    if (ret) {
      cout << "ERROR: create thread failed: " << ret << endl;
      exit(0);
    }
    cout << "OK: create thread done" << endl;
  }
  for (int i = 0; i < N; i++) {
    cout << "join thread: " << ths[i].id << endl;
    ret = pthread_join(ths[i].id, NULL);
    if (ret) {
      cout << "ERROR: join thread failed: " << ret << endl;
      exit(0);
    }
    cout << "OK: join thread done" << endl;
  }
  cout << "thread returns: " << get_tid() << endl;
  return 0;
}
