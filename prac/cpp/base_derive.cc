#include <cstring>
#include <string>
#include <list>
#include <map>
#include <iostream>

using namespace std;
// test drive
class Base {
  public:
    string name;
    int age;
    void show() {
      cout << get_name() << endl;
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
  Base *pbase = new Base();
  Base *bptr;

  bptr = pbase;
  bptr->show ();
  bptr = pderive;
  bptr->show ();
  return 0;
}
