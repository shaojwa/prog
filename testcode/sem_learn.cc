#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <iostream>
using namespace std;

int gettid() {
  return syscall(SYS_gettid);
}
void* start_routine(void *param) {
  sem_t *psem = (sem_t*)param;
  // sleep(1);
  int count = 0;
  while(true) {
    cout << gettid() << " ++++ " << ++count << endl;
    if (0 != sem_post(psem)) {
      cout << gettid() << " sem_post fail" << endl;
      return 0;
    }
    sleep(5);
  }
  return 0;
}


int main(int argc, char *argv[]) {
  sem_t sem;
  pthread_t tid;
  int ret = sem_init(&sem, 0, 0);
  if (ret !=  0) {
    cout << gettid() << " sem init failed " << endl;
    exit(-1);
  }
  ret = pthread_create(&tid, NULL, start_routine, &sem);
  if (0 != ret) {
    cout << gettid() << " primary thread, create thread fail." << endl;
    exit(-1);
  }
  char flag = 0;
  int count = 0;
  while (true) {
    cin >> flag;
    if (flag == '0') {
      cout << "break" << endl;
      break;
    }
    ret = sem_wait(&sem);
    cout << gettid() << " ---- " << ++count << endl;
  }
  void *retval = nullptr;
  pthread_join(tid, &retval);
  pthread_exit(&retval);
}
