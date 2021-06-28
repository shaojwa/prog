#include <iostream>
using namespace std;

int main() {
  int a = 10;
  int &r = a;
  auto b = r;
  b = 20;
  cout << "a = " << a << ", r = " << r << ", b = " << b << endl;
  return 0;
}
