#include <cstring>
#include <string>
#include <list>
#include <map>
#include <iostream>
#include <unistd.h>

using namespace std;
// test drive
class Base {
  public:
    string name;
    int age;
    void show(int x, int y) {
      sleep(1000 + 100*x + 10 * y);
    }
    virtual string get_name() {
      return "base::get_name()";
    }
    virtual void f() {
      cout << "base::f()" << endl;
    }
    virtual void g() {
      cout << "base::g()" << endl;
    }
    void h() {
      cout << "base::x()" << endl;
    }
};


class Derive: public Base {
  string get_name() {
    return "derive::get_name()";
  }
  virtual void f() {
    cout << "drive::f()"  << endl;
  }
  virtual void g() {
    cout << "drive::g()"  << endl;
  }
};


int main (int argc, char * argv[])
{
  Derive *pderive = new Derive();
  cout << pderive << endl;
  pderive->show(2,3);
  return 0;
}
