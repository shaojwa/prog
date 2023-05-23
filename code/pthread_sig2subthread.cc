#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int get_tid() 
{
  return syscall(SYS_gettid);
}

void sig_action(int signum , siginfo_t *psi, void *pcontext)
{
  cout << "****signum " << signum << ", si_tid " << psi->si_pid  << ", si_code " << psi->si_code << endl;
}


void sig_init(int signum)
{
  cout << "sigaction " << get_tid()  << ", signum " << signum << endl;
  struct sigaction myact;
  memset(&myact, 0, sizeof(myact));
  myact.sa_sigaction = sig_action;
  sigemptyset(&myact.sa_mask);
  myact.sa_flags = SA_SIGINFO;
  sigaction(signum, &myact, NULL);
}

void examine_sigs()
{
  // signals
  for (int i = 0; i < 32; i++) {
    sig_init(i);
  }
  //sig_init(SIGINT);
  //sig_init(SIGABRT);
  //sig_init(SIGQUIT);
  //sig_init(SIGKILL);
  //sig_init(SIGSTOP);
  //sig_init(SIGTSTP);
  //sig_init(SIGTERM);
  //sig_init(SIGPWR);
  //
}

static void *start_fn(void *arg)
{
  int n = *(int*)arg;
  cout << "thread started " << get_tid() << ", n "  << n << endl;
  examine_sigs();
  cout << "thread " << get_tid()  << ", lool sleep " << endl;
  int i = 0;
  while (true) {
    cout << "#" << i << " sleep " << n + 1 << " seconds" << endl;
    sleep (n + 1);
    i++; }
  cout << "thread exit " << get_tid() << endl;
}

struct thread_t
{
  void *(*fn)(void*);
  pthread_t id;
  int tid;
  int arg;
};

int main(int argc, char* argv[]) {
  int ret;
  int N = 1;
  thread_t ths[N];
  cout << "main thread " << get_tid() << endl;
  for (int i = 0; i < N; i++) {
    ths[i].fn = start_fn;
    ths[i].arg = i;
    ret = pthread_create(&ths[i].id, NULL, ths[i].fn, (void *)&ths[i].arg);
    if (ret) {
      cout << "ERROR: create thread failed: " << ret << endl;
      exit(0);
    }
    cout << "thread created " << ths[i].id << endl;
  }
  sleep(10);
  /*
  for (int i = 0; i < N; i++) {
    cout << "join thread: " << ths[i].id << endl;
    ret = pthread_join(ths[i].id, NULL);
    if (ret) {
      cout << "ERROR: join thread failed: " << ret << endl;
      exit(0);
    }
    cout << "OK: join thread done" << endl;
  }
  */
  cout << "thread exit " << get_tid() << endl;
  pthread_exit(0);
  return 0;
}
