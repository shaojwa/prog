#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>
#include <iostream>

using namespace std;

pthread_mutex_t glock;
pthread_cond_t gcond;

int bound = 0;
int count = 0;

int gettid() {
  return syscall(SYS_gettid);
}

int increase(int n) {
  pthread_mutex_lock(&glock);
  count++;
  cout << n;
  pthread_mutex_unlock(&glock);
}

int increase_inturn(int n) {
  pthread_mutex_lock(&glock);
  while(true) {
    cout << n << ":" << count << endl;
    if (count == bound) {
      cout << n << ":" << "break" << endl;
      break;
    }
    count++;
    pthread_cond_signal(&gcond);
    //cout << "before wait: " << n << endl;
    pthread_cond_wait(&gcond, &glock);
    //cout << "after wait: " << n << endl;
  }
  pthread_cond_signal(&gcond);
  pthread_mutex_unlock(&glock);
}

void* start_routine(void *param) {
  increase_inturn(1);
  int retval;
  pthread_exit(&retval);
}


int main(int argc, char *argv[]) {
  pthread_t tid;
  pthread_mutex_init(&glock, NULL);
  pthread_cond_init(&gcond, NULL);
  if (argc == 2) {
    bound = atoi(argv[1]);
  } else {
    cout << "usage: " << argv[0] << " <num> " << endl;
    exit(0);
  }
  int ret = pthread_create(&tid, NULL, start_routine, NULL);
  if (0 != ret) {
    printf("primary thread, create thread fail.\n");
  }
  int i = 0;
  increase_inturn(0);
  void *pretval = NULL;
  pthread_join(tid, &pretval);
  pthread_exit(pretval);
}
