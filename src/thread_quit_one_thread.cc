#include <unistd.h>
#include <sys/syscall.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <set>
#include <iostream>

using namespace std;

pthread_mutex_t glock;

int get_tid() {
  return syscall(SYS_gettid);
}

void* insert_routine(void *param) {
  while (true) {
    pthread_mutex_lock(&glock);
    cout << "thread " << get_tid() << " lock" << endl;
    sleep(5);
    cout << "thread " << get_tid() << " unlock" << endl;
    pthread_mutex_unlock(&glock);
    sleep(5);
  }
}


void handle_signal(int sig) {
  cout << "thread "  << get_tid() << " handle signal " << sig << endl;
  if (sig == SIGQUIT) {
    cout << "thread exit " << get_tid() << endl;
    pthread_exit(0);
  } else if (sig == SIGTSTP) {
    cout << "thread " << get_tid() << " lock" << endl;
    pthread_mutex_lock(&glock);
  } else if (sig == SIGCONT) {
    cout << "thread " << get_tid() << " unlock" << endl;
    pthread_mutex_unlock(&glock);
  }
}

int main(int argc, char *argv[]) {
  cout << "primary thread " << get_tid() << " start" << endl;
//  signal(SIGKILL, handle_signal);
//  signal(SIGSTOP, handle_signal);
  signal(SIGTSTP, handle_signal);
  signal(SIGCONT, handle_signal);
  signal(SIGINT, handle_signal);
  signal(SIGQUIT, handle_signal);
  signal(SIGTERM, handle_signal);
  signal(SIGHUP, handle_signal);
  pthread_t t1, t2;
  pthread_create(&t1, NULL, insert_routine, NULL);
  sleep(5);
  pthread_create(&t2, NULL, insert_routine, NULL);
  pthread_join(t1, nullptr);
  pthread_join(t2, nullptr);
  cout << "primary thread " << get_tid() << " exit" << endl;
  pthread_exit(nullptr);
}
