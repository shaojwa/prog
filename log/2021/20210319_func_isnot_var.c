#include <stdio.h>

int twice(int n) {
  return 2*n;
}

int main() {
  int (*fp)(int);
  fp = twice;
  printf("%p\n", twice);
  printf("%p\n", &twice);
  printf("%p\n", fp);
  printf("%p\n", &fp);
  printf("%d\n", fp(5));
  return 0;
}
