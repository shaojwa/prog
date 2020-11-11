

#include <iostream>

using namespace std;

class Base {
  public:
    virtual void f() {
      cout << "base::f()" << endl;
    }
    void h() {
      f();
    }
};


class Derive: public Base {
  virtual void f() {
    cout << "derive::f()"  << endl;
  }
};


int main (int argc, char * argv[])
{
  Derive *pderive = new Derive();
  pderive->h();
  return 0;
}
