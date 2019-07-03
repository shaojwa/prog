#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/uio.h>
#include <iostream>

using namespace std;

void test_writev() {
  char str0[] = "hello ";
  char str1[] = "world\n";
  struct iovec iov[2];
  ssize_t nwritten;

  iov[0].iov_base = str0;
  iov[0].iov_len = strlen(str0);
  iov[1].iov_base = str1;
  iov[1].iov_len = strlen(str1);

  nwritten = writev(STDOUT_FILENO, iov, 2);
  printf("nwritten = %zu\n", nwritten);
}

void open2keep(const char *path) {
  FILE *fp = fopen(path, "w");
  if(NULL == fp) {
    cout << "fopen failed with errno: " << errno << endl;
    return;
  }
  cout << "begin sleep" << endl;
  sleep(10);
  cout << "end sleep" << endl;
  fclose(fp);
  return;
}

int main(void) {
  test_writev();
  return 0;
}
