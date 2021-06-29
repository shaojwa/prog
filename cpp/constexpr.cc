//
// static_assert, performing a compile-time  checking
//
#include <iostream>
using namespace std;

constexpr int square(int n) {
  // in c++11, there should be only one return-statement in constexpr function
  // but this restriction was lifted in c++14
  if (n == 0) {
    return 0;
  }
  return n * n;
}

int main() {
  int n = square(-1);
  cout << n << endl;
  return 0;
}

