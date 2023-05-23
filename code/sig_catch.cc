#include <signal.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <iostream>

using namespace std;

#define dout cout << "pid " << getpid() << ", " <<  __func__ << ", "


void sig_action(int signum , siginfo_t *psi, void *pcontext) {
  cout << "signum " << signum << ", si_tid " << psi->si_pid  << ", si_code " << psi->si_code << endl;
}
void sig_init(int signum) {
  struct sigaction myact;
  memset(&myact, 0, sizeof(myact));
  myact.sa_sigaction = sig_action;
  sigemptyset(&myact.sa_mask);
  myact.sa_flags = SA_SIGINFO;
  sigaction(signum, &myact, NULL);
}


int main(int argc, char* argv[]) {
  // signals
  sig_init(SIGINT);
  sig_init(SIGABRT);
  sig_init(SIGQUIT);
  sig_init(SIGKILL);
  sig_init(SIGSTOP);
  sig_init(SIGTSTP);
  sig_init(SIGTERM);
  sig_init(SIGPWR);
  //
  while (true) {
    sleep(100);
  }
  return 0;
}
