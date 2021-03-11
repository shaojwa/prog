// 确实非常好用，写了个简单的代码进行测试
#include <iostream>
#include <stdlib.h>
using namespace std;

void nofree(int x) {
  int i;
  cout << "leak " << x * x * sizeof(1024) + x *sizeof(void*) << " bytes" << endl;
  void **index = (void **)malloc(x * sizeof(void *));
  for (i = 0; i < x; i++) {
    index[i] = malloc(x * sizeof(1024));
    cout << index + i << " index[" << i << "]=" << index[i] << endl;
  }
  index[i] = 0; // invalid of write
}

void noinit() {
  int x;
  int sum = 0;
  sum += x;
  //cout << "sum is " << sum << endl;
  if (sum != 0) {
    cout << "sum is not 0" << endl;
  } else {
    cout << "sum is 0" << endl;
  }
}

int main() {
  nofree(10);
  noinit();
  return 0;
}
