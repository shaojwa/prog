#include <stdio.h>

#define dout(var) printf("%s = %d\n", #var, (var))

int main(void) {
  dout(1 + 2);
  return 0;
}
