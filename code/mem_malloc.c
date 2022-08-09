#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ntimes() {
  void **ptrs = 0;
  int n = 0;
  int f = 0;
  printf("please input the times to malloc: ");
  scanf("%d", &n);
  printf("n = %d\n", n);
  ptrs = malloc(n*sizeof(void*));
  int i = 0;
  int amount = 0;
  for (i = 0; i < n; i++) {
    amount = rand() % 1024;
    printf("amount = %d\n", amount);
    ptrs[i] = malloc(1024 * 1024 * amount);
  }
  printf("please press 0 to free: ");
  scanf("%d", &f);
  for (i = 0; i < n; i++) {
    free(ptrs[i]);
  }
  return 0;
}

int once() {
  void *ptr = 0;
  int n = 0;
  int flag = 0;
  printf("please input the size of memory to malloc(in MB): ");
  scanf("%d", &n);
  printf("n = %d\n", n);
  if (!n) {
    return 0;
  }
  ptr = malloc(1024*1024*n);
  memset(ptr, 1, 1024*1024*n);
  printf("ptr = %p\n", ptr);
  printf("free memory(0:no, 1:yes): ");
  scanf("%d", &flag);
  if (flag && ptr) {
    printf("free memory\n");
    free(ptr);

  }
}

int main() {
  int flag;
  while (1) {
    printf("please select to test once or ntimes(1: once, 2: ntime, 0: quit): ");
    scanf("%d", &flag);
    if (flag == 1) once();
    else if (flag == 2) ntimes();
    else  return 0;
  }
}

