#include <iostream>
using namespace std;


struct state {
  int age;
};

class Base {
  public:
    ~Base() {
      cout << "Base:~Base()" << endl;
    }
    Base() {
      cout << "Base::Base()" << endl;
    }
    void dump(state *state) {
      cout << age << endl;
    }
    int age;
};

int main (int argc, char * argv[])
{
  Base b;
  state s;
  b.dump(&s);
  return 0;
}
