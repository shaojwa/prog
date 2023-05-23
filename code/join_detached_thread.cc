#include <sys/syscall.h>
#include <signal.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <iostream>
using namespace std;

#define dout (cout << __func__ << ": ")

int gettid() { return syscall(__NR_gettid); }
//int gettid() { return syscall(SYS_gettid); }


void handle_sig(int signum) {
  dout << "tid " << gettid() << ", signum " << signum << endl;
  if (signum == SIGINT) {
    pthread_exit(0);
  }
}

void sig_init() {
  signal(SIGINT, handle_sig);
  signal(SIGSTOP, handle_sig);
}

void sig_init_thread() {
  //signal(SIGINT, handle_sig);
  signal(SIGABRT, handle_sig);
}

static void *start_routine(void *arg)
{
  dout << "start " << gettid() << endl;
  sig_init_thread();
  uint i = 0;
  while (true) {
    dout << "#" << gettid() << " sleep seconds " << i << endl;
    sleep (5);
    i++;
  }
  dout << " exit " << gettid() << endl;
}


int main(int argc, char* argv[]) {
  int err = 0;
  dout << gettid() << endl;
  sig_init();

  pthread_t th;
  pthread_attr_t attr;
  err = pthread_attr_init(&attr);
  if (err) {
    dout << "init attr failed, err " << err << endl;
  }
  err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
  if (err) {
    dout << "set detach state faile, err " << err << endl;
  }

  err = pthread_create(&th, &attr, start_routine, 0);
  if (err) {
    dout << "create thread failed, err " << err << endl;
  }

  err = pthread_join(th, 0);
  if (err) {
    dout << "join thread failed, err " << err << endl;
    exit(0);
  }
  dout << "join thread success" << endl;
  dout << "raise SIGKILL" << endl;
  //err = raise(SIGABRT);
  //err = raise(SIGKILL);
  dout << "returns with: " << err << endl;
  return err;
}
