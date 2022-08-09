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
void sig_sethdl(int signum) {
  sighandler_t ph = signal(signum, sig_handler); 
  if (SIG_ERR == ph) {
    dout << "signal signum " << signum << " fail, errno is " << errno << endl;
  } else {
    dout << "signal signum " << signum  << " done, ph " << ph << endl;
  }
}


void sig_ign(int signum) {
  sighandler_t ph = signal(signum, SIG_IGN); 
  if (SIG_ERR == ph) {
    dout << "ign signum " << signum << " fail, errno is " << errno << endl;
  } else {
    dout << "ign signum " << signum  << " done, pg " << ph << endl;
  }
}

int main(int argc, char* argv[]) {
  // signals
  sig_sethdl(SIGKILL);
  sig_sethdl(SIGSTOP);
  sig_sethdl(SIGINT);
  //
  sig_ign(SIGKILL);
  sig_ign(SIGSTOP);
  sig_ign(SIGINT);
  sleep(100);
  return 0;
}
