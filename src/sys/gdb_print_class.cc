#include <iostream>
using namespace std;


struct state_t {
  int num = 0;
};

class Base {
  public:
    ~Base() {
      cout << "Base:~Base()" << endl;
    }
    Base() {
      cout << "Base::Base()" << endl;
    }
    void dump(state_t *state) {
      cout << age << endl;
    }
    int age = 0;
};

int main (int argc, char * argv[])
{
  Base b;
  state_t s;
  b.dump(&s);
  return 0;
}
