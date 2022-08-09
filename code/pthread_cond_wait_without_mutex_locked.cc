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


int gettid() {
  return syscall(SYS_gettid);
}

void* start_lock_mutex(void *) {
  int ret = pthread_mutex_lock(&glock);
  if (ret == 0) {
    cout << gettid() << " mutex lock done" << endl;
  } else {
    cout << gettid() << " mutex lock fail, err " << ret << endl;
  }
  sleep(10);
  pthread_mutex_unlock(&glock);
  cout << gettid() << " mutex unlock " << endl;
  return 0;
}


void create_thread_to_lock_mutex(pthread_t *ptid) {
  int ret = pthread_create(ptid, NULL, start_lock_mutex, NULL);
  if (0 != ret) {
    cout << gettid() << " error: create thread fail" << endl;
  }
}


void* start_wait_cond(void *) {
  while(true) {
    cout << gettid() << " try cond_wait" << endl;
    int ret = pthread_cond_wait(&gcond, &glock);
    if (ret == 0) {
      cout << gettid() << " got signal and lock" << endl;
      return 0;
    }
    cout << gettid() << " cond_wait fail. err " << ret << endl;
    if (ret == EPERM) {
      cout << gettid() << " try lock mutex" << endl;
      ret = pthread_mutex_lock(&glock);
      if (ret != 0) {
        cout << gettid() << " lock fail. err " << ret << endl;
      } else {
        cout << gettid() << " mutex locked " << endl;
      }
    }
    cout << gettid() << " sleep 1s " << endl;
    sleep(1);
  }
  return 0;
}

void create_thread_to_wait_cond(pthread_t *ptid) {
  int ret = pthread_create(ptid, NULL, start_wait_cond, NULL);
  if (0 != ret) {
    cout << gettid() << " error: create thread fail" << endl;
  }
}


void* start_signal_cond(void *) {
  while(true) {
    int flag;
    cout << gettid() << " signal or not ? " << endl;
    cin >> flag;
    if (flag == 0) {
      cout << gettid() << " do signal " << endl;
      int ret = pthread_cond_signal(&gcond);
      if (ret == 0) {
        cout << gettid() << " signal done" << endl;
      } else {
        cout << gettid() << " signal fail, err " << ret << endl;
      }
      return 0;
    }
    cout << gettid() << " no signal" << endl;
  }
  return 0;
}

void create_thread_to_signal_cond(pthread_t *ptid) {
  int ret = pthread_create(ptid, NULL, start_signal_cond, NULL);
  if (0 != ret) {
    cout << gettid() << " error: create thread fail" << endl;
  }
}


int main(int argc, char *argv[]) {
  pthread_t tid_lock;
  pthread_t tid_wait;
  pthread_t tid_signal;

  pthread_mutexattr_t attr;
  pthread_mutexattr_init(&attr);
  pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
  pthread_mutex_init(&glock, NULL);
  pthread_cond_init(&gcond, NULL);

  cout << gettid() << " create tid_lock" << endl;
  create_thread_to_lock_mutex(&tid_lock);
  sleep(1);
  cout << gettid() << " create tid_wait" << endl;
  create_thread_to_wait_cond(&tid_wait);
  sleep(1);
  cout << gettid() << " create tid_signal" << endl;
  create_thread_to_signal_cond(&tid_signal);
  sleep(1);
  cout << gettid() << " join tid_lock" << endl;
  pthread_join(tid_lock, NULL);
  cout << gettid() << " join tid_wait" << endl;
  pthread_join(tid_wait, NULL);
  cout << gettid() << " join tid_signal" << endl;
  pthread_join(tid_signal, NULL);
  cout << gettid() << " exit" << endl;
  return 0;
}
