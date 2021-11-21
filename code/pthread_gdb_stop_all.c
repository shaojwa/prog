#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdint.h>


int gettid2() {
  return syscall(SYS_gettid);
}

void* routine1(void *param) {
  int i = 0;
  while (i++ < 20) {
    printf("%s - %d\n", __func__, i);
    sleep(10);
  }
  return nullptr;
}

void* routine2(void *param) {
  int i = 0;
  while (i++ < 20) {
    printf("%s - %d\n", __func__, i);
    sleep(10);
  }
  return nullptr;
}

void* routine3(void *param) {
  uint64_t loop = 0;
  while (true) {
    loop++;
  }
  return nullptr;
}

int main(void) {
  pthread_t tid1;
  int ret = pthread_create(&tid1, NULL, routine1, NULL);
  if (0 != ret) {
    printf("create thread failed.\n");
  }

  pthread_t tid2;
  ret = pthread_create(&tid2, NULL, routine2, NULL);
  if (0 != ret) {
    printf("create thread failed.\n");
  }

  pthread_t tid3;
  ret = pthread_create(&tid3, NULL, routine3, NULL);
  if (0 != ret) {
    printf("create thread failed.\n");
  }

  void *ret1, *ret2, *ret3;
  pthread_join(tid1, &ret1);
  pthread_join(tid2, &ret2);
  pthread_join(tid3, &ret3);
}
