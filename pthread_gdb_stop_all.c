#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>

int gettid2() {
  return syscall(SYS_gettid);
}

void* rtn1(void *param) {
  int i = 0;
  while (i++ < 20) {
    printf("%s - %d\n", __func__, i);
    sleep(10);
  }
}

void* rtn2(void *param) {
  int i = 0;
  while (i++ < 20) {
    printf("%s - %d\n", __func__, i);
    sleep(10);
  }
}

int main(void) {
  pthread_t tid1;
  pthread_t tid2;
  int ret = pthread_create(&tid1, NULL, rtn1, NULL);
  if (0 != ret) {
    printf("create thread failed.\n");
  }

  ret = pthread_create(&tid2, NULL, rtn2, NULL);
  void *ret1, *ret2;
  if (0 != ret) {
    printf("create thread failed.\n");
  }
  pthread_join(tid1, &ret1);
  pthread_join(tid2, &ret2);
}
