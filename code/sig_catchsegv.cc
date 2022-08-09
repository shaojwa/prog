#include <signal.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <iostream>

using namespace std;

#define dout cout << "pid " << getpid() << ", " <<  __func__ << ", "

void sig_handler(int signum) {
  dout << "handle sig " << signum << endl;
  exit(0);
}
void sig_init(int signum) {
  sighandler_t ph = signal(signum, sig_handler); 
  if (SIG_ERR == ph) {
    dout << "signal " << signum << " fail, errno is " << errno << endl;
  } else {
    dout << "signal " << signum  << " done, prev handler " << ph << endl;
  }
}
int main(int argc, char* argv[]) {
  // signals
  sig_init(SIGSEGV);
  dout << *((int *)(0)) << endl;
  sleep(5);
  return 0;
}
