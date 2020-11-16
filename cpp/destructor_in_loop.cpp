#include <iostream>
using namespace std;

class Lock {
public:
  Lock(int n) {
    cout << "lock(" << n << ")" << endl;
  }
  ~Lock() {
    cout << "~lock()" << endl;
  }
private:
  int state;
};


int main() {
  int count = 10;
  while (count--) {
    Lock l(count);  
  }
  return 0;
}
