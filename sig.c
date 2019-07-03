#include <signal.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <iostream>

using namespace std;


void raise_alarm();
void raise_abort();
void handle_abort(int signum);
void handle_interrupt(int signum);
void sig_sicodes();
void sig_init1();
void sig_init2(int);


void raise_alarm() {
  raise(14);
}

void raise_abort() {
  abort();
}

void handle_abort(int signum) {
  cout << "tid = " << get_tid() << ", signum=" << signum << endl;
}

void handle_interrupt(int signum) {
  cout << "tid = " << get_tid() << ", signum=" << signum << endl;
}

void sig_init1() {
  signal(SIGINT, handle_interrupt);
  signal(SIGABRT, handle_abort);
}


void sighandle(int signum , siginfo_t *psi, void *pcontext) {
  cout << "signum: " << signum << ", si_tid: " << psi->si_pid  << ", si_code: " << psi->si_code << endl;
}

void sig_init2(int signum) {
  struct sigaction myact;
  memset(&myact, 0, sizeof(myact));
  myact.sa_sigaction = sighandle;
  sigemptyset(&myact.sa_mask);
  myact.sa_flags = SA_SIGINFO;
  sigaction(signum, &myact, NULL);
}

void sig_sicodes() {
  cout << "SI_USER   \t" << SI_USER << endl;
  cout << "SI_KERNEL \t" << SI_KERNEL << endl;
  cout << "SI_QUEUE  \t" << SI_QUEUE << endl;
  cout << "SI_TIMER  \t" << SI_TIMER << endl;
  cout << "SI_MESGQ  \t" << SI_MESGQ << endl;
  cout << "SI_ASYNCIO\t" << SI_ASYNCIO << endl;
  cout << "SI_SIGIO  \t" << SI_SIGIO << endl;
  cout << "SI_TKILL  \t" << SI_TKILL << endl;
}

int main(int argc, char* argv[]) {
  // signals
  sig_init2(SIGINT);
  sig_init2(SIGTERM);
  sig_init2(SIGTSTP);
  sig_init2(SIGALRM);
  sig_sicodes();
  int ret = raise(SIGALRM);
  cout << "raise returns: " << ret << endl;
  tm_sleep(100);
  return 0;
}
