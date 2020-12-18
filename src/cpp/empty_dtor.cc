// testing if the user-declared destructor is in need
// when user-declared destructor is defined in Base class

#include <iostream>
using namespace std;
class A {
  public:
    ~A() {
      cout << "~A()" << endl;
    };
};

class B : A {
  public:
    B() {
      cout << "B()" << endl;
    }
};
int main() {
  B b;
  return 0;
} 
