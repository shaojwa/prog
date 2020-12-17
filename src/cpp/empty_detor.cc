#include <iostream>
using namespace std;
struct A {
  private:
    ~A() {
      cout << "~A()" << endl;
    };
};
struct B : A {
//  ~B() {
//    cout << "~B()" << endl;
//  };
};
int main() {
  return 0;
} 
