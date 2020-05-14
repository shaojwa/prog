#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>
#include <iostream>

using namespace std;


int threads_count = 10;
pthread_mutex_t glock;


int gettid() {
  return syscall(SYS_gettid);
}

int wait_to_lock() {
  pthread_mutex_lock(&glock);
  cout << "got lock... i am thread " << gettid() << endl;
  sleep(1);
  pthread_mutex_unlock(&glock);
}


void* start_routine(void *param) {
  // cout << "i am #" << reinterpret_cast<int>(param) << " thread " << gettid() << endl;
  cout << "i am #" << (long long)param << " thread " << gettid() << endl;
  wait_to_lock();
}


void create_threads(pthread_t threads[], int threads_count) {
  for (int i = 0; i < threads_count; i++) {
    // cout << "create thread " << i << endl;
    int ret = pthread_create(&threads[i], NULL, start_routine, reinterpret_cast<void *>(i));
    if (0 != ret) {
      cout << " error: create thread fail. i " << i << endl;
    }
    // cout << "create thread success, sleep 1 second,  tid " << threads[i] << endl;
    sleep(1);
  }
}

void join_threads(pthread_t threads[], int threads_count) {
  for (int i = 0; i < threads_count; i++) {
    pthread_join(threads[i], NULL);
  }
}


int main(int argc, char *argv[]) {
  pthread_t tids[threads_count];

  pthread_mutex_init(&glock, NULL);
  pthread_mutex_lock(&glock);
  cout << "create threads" << endl;
  create_threads(tids, threads_count);
  cout << "unlock" << endl;
  pthread_mutex_unlock(&glock);
  cout << "join threads" << endl;
  join_threads(tids, threads_count);
  return 0;
}
