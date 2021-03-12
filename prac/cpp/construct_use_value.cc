#include <iostream>
using namespace std;


class Base {
  public:
    ~Base() {
      cout << "Base:~Base()" << endl;
    }
    Base() {
      cout << "Base::Base()" << endl;
    }
    
    Base(Base &b) {
      cout << "Base::Base(&Base b)" << endl;
    }

    Base(const Base &b) {
      cout << "Base::Base(const Base &b)" << endl;
    }

    Base(Base && b) {
      cout << "Base::Base(Base && b)" << endl;
    }
    Base get_instance() {
      cout << "Base::get_instance()" << endl;
      return *this;
    }
    Base &get_inst_ref() {
      cout << "Base::get_inst_ref()" << endl;
      return *this;
    }
    int age;
};

class Dog {
  public:
  void use_val(Base b) {
    cout << "use_val(Base b)" << endl;
  }
  void use_ref(Base &b) {
    cout << "use_ref(Base &b)" << endl;
  }
  void use_ref(const Base &b) {
    cout << "use_ref(const Base &b)" << endl;
  }
  /*
  void use_ref(Base &&b) {
    cout << "use_ref(Base &&b)" << endl;
  }
  */

  string name;
};

int main (int argc, char * argv[])
{
  Base b1;
  Dog d1;
  d1.use_ref(b1.get_instance());
  d1.use_val(b1.get_instance());
  //d1.use_ref(b1.get_inst_ref());
  //d1.use_val(b1.get_inst_ref());
  return 0;
}
