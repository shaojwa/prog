
#include <iostream>
using  namespace std;

int func(int &n) {
  n *= 2;
}

int main() {
  int a = 10;
  int &b = a;
  auto &c = b;
  func(c);
  return 0;
 }
