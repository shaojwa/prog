#include <unistd.h>
#include <sys/syscall.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <set>
#include <iostream>

using namespace std;

int get_tid() {
  return syscall(SYS_gettid);
}

void* insert_routine(void *param) {
  while (true) {
    cout << "thread " << get_tid() << endl;
    sleep(2);
  }
}


void handle_signal(int sig) {
  cout << "thread "  << get_tid() << " handle signal " << sig << endl;
  if (sig == SIGQUIT) {
    cout << "thread exit " << get_tid() << endl;
    pthread_exit(0);
  } 
}


int main(int argc, char *argv[]) {
  // signal(SIGHUP, handle_signal);
  signal(SIGINT, handle_signal);
  signal(SIGQUIT, handle_signal);
  signal(SIGKILL, handle_signal);
  signal(SIGSTOP, handle_signal);
  // signal(SIGTSTP, handle_signal);
  pthread_t t1, t2;
  pthread_create(&t1, NULL, insert_routine, NULL);
  sleep(5);
  pthread_create(&t2, NULL, insert_routine, NULL);
  pthread_join(t1, nullptr);
  pthread_join(t2, nullptr);
  pthread_exit(nullptr);
}
