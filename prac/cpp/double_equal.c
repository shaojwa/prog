#include <stdio.h>

int main() {
  float a = 0.1, b = 0.05;
  b += 0.05;
  if (a == b) {
    printf("equal\n");
  } else {
    printf("not equal\n");
  }
  return 0;
}
    
