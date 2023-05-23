#include <signal.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <iostream>
using namespace std;

#define dout cout << "pid " << getpid() << ", " <<  __func__ << ", "

void sig_ign(int signum) {
  sighandler_t ph = signal(signum, SIG_IGN); 
  if (SIG_ERR == ph) {
    dout << "ign signum " << signum << " fail, errno is " << errno << endl;
  } else {
    dout << "ign signum " << signum  << " done, pg " << ph << endl;
  }
}

int main(int argc, char* argv[]) {
  sig_ign(SIGSEGV);
  dout << *((int *)(0)) << endl;
  sleep(0);
  dout << "exit" << endl;
  return 0;
}
