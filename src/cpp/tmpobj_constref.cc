#include <iostream>
#include <unistd.h>

using namespace std;
class A {
  int  num;
  public:
  int get_num() const {
    return num;
  }
};

class B {
  int num;
  public:
    B() {
      cout << "B()" << endl;
    }
    void func(A &a) {
      num = a.get_num();
    }
};

int main() {
  B b;
  b.func(A());
  return 0;
} 
