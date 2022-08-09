#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>
#include <iostream>

using namespace std;

int threads_count = 100;
pthread_mutex_t glock;


int gettid() {
  return syscall(SYS_gettid);
}

int wait_to_lock(long long num) {
  pthread_mutex_lock(&glock);
  cout << "got lock. i am thread #" << num << ", tid " << gettid() << endl;
  pthread_mutex_unlock(&glock);
  return 0;
}


void* start_routine(void *param) {
  // cout << "i am #" << reinterpret_cast<int>(param) << " thread " << gettid() << endl;
  long long num = (long long)param;
  cout << "i am thread #" << num << " tid " << gettid() << endl;
  wait_to_lock(num);
  return nullptr;
}


void create_threads(pthread_t threads[], int threads_count) {
  for (int i = 0; i < threads_count; i++) {
    cout << "create thread " << i << endl;
    int ret = pthread_create(&threads[i], NULL, start_routine, reinterpret_cast<void *>(i));
    if (0 != ret) {
      cout << " error: create thread fail. i " << i << endl;
    }
    cout << "create thread success, tid " << threads[i] << endl;
    usleep(1000);
  }
}

void join_threads(pthread_t threads[], int threads_count) {
  for (int i = 0; i < threads_count; i++) {
    pthread_join(threads[i], nullptr);
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
  cout << "done" << endl;
  return 0;
}
