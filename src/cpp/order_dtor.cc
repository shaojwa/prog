// testing if the user-declared destructor is in need
// when user-declared destructor is defined in Base class

#include <iostream>
#include <unistd.h>

using namespace std;
class A {
  public:
    A() {
      cout << "A()" << endl;
    }
    ~A() {
      cout << "~A()" << endl;
    };
};

class B {
  public:
    B() {
      cout << "B()" << endl;
    }
    ~B() {
      cout << "~B()" << endl;
    }
};

class C : A {
  B b;
  public:
  C() {
    cout << "C()" << endl;
  }
};
int main() {
  C c;
  return 0;
} 
