#include <signal.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <iostream>

using namespace std;

#define dout cout << "pid " << getpid() << ", " <<  __func__ << ", "

void sig_handler(int signum) {
  dout << "signum " << signum << endl;
}
void sig_init1(int signum) {
  sighandler_t ph = signal(signum, sig_handler); 
  if (SIG_ERR == ph) {
    dout << "signal signum " << signum << " fail, errno is " << errno << endl;
  } else {
    dout << "signal signum " << signum  << " done, prev handler " << ph << endl;
  }
}


void sig_action(int signum , siginfo_t *psi, void *pcontext) {
  cout << "signum " << signum << ", si_tid " << psi->si_pid  << ", si_code " << psi->si_code << endl;
}
void sig_init2(int signum) {
  struct sigaction myact;
  memset(&myact, 0, sizeof(myact));
  myact.sa_sigaction = sig_action;
  sigemptyset(&myact.sa_mask);
  myact.sa_flags = SA_SIGINFO;
  sigaction(signum, &myact, NULL);
}


void raise_alarm() {
  raise(14);
}

void raise_abort() {
  abort();
}

int main(int argc, char* argv[]) {
  // signals
  sig_init1(SIGKILL);
  sig_init1(SIGSTOP);
  sig_init1(SIGINT);
  //
  //sig_init2(SIGINT);
  //sig_init2(SIGTERM);
  //sig_init2(SIGTSTP);
  //sig_init2(SIGALRM);
  //int ret = raise(SIGALRM);
  //cout << "raise returns: " << ret << endl;
  sleep(100);
  return 0;
}
