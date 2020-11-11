#include <cstring>
#include <string>
#include <list>
#include <map>
#include <iostream>
using namespace std;

class Base {
  public:
    Base() {
      cout << "base::Base()" << endl;
    }
    
    Base(Base b) {
      cout << "base::Base(const Base b)" << endl;
    }

    Base(Base &b) {
      cout << "base::Base(const Base &b)" << endl;
    }

    Base(Base && b) {
      cout << "base::Base(Base && b)" << endl;
    }
};

class D {
	D(Base b) {}
	D(Base &b) {}
};

int main (int argc, char * argv[])
{
  Base b1;
  Base b2(b1);
  return 0;
}
