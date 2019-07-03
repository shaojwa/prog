#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


uint64_t test_interval() {
  struct timeval from, to;
  gettimeofday(&from, NULL);
  sleep(1);
  gettimeofday(&to, NULL);
  return (to.tv_sec * 1000000 + to.tv_usec - from.tv_sec * 1000000 - from.tv_usec);
}


unsigned int tm_sleep(unsigned int seconds) {
  printf("start sleep %u seconds\n", seconds);
  unsigned int ret = sleep(seconds);
  printf("finish sleep, left %u seconds\n", ret);
}

int main(int argc, char* argv[]) {
  tm_sleep(10);
  return 0;
}
