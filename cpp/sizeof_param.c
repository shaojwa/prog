#include <stdio.h>
#include <stdlib.h>

int func(char buf[100]) {
  char arr[100];
  printf("sizeof buf: %u\n", sizeof(buf));
  printf("sizeof arr: %u\n", sizeof(arr));
  return 0;
}

int main(void) {
  char buff[200];
  func(buff);
  return 0;
}
