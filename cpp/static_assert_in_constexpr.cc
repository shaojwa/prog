//
// static_assert cannot used in constexptr
//
#include <iostream>
using namespace std;

constexpr int square(int n) {
  static_assert(n != 0); // error: ‘n’ is not a constant expression
  return n * n;
}

int main() {
  int n = square(0);
  cout << n << endl;
  return 0;
}

