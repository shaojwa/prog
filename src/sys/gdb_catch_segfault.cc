#include <iostream>

using namespace std;

int div_zero(int x, int y) {
  return x/y;
}

void use_pointer(int *ptr, int x) {
  *ptr = x;
}

int main() {
  div_zero(1, 0);
  // use_pointer(nullptr, 1);
  return 0;
}
