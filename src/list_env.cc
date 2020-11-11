#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main() {
  pid_t ppid = getppid();
  cout << ppid << endl;
  char *pvalue = getenv("PATH");
  cout << pvalue << endl;
  pvalue = getenv("HOME");
  cout << pvalue << endl;
  sleep(60);
  return 0;
}
