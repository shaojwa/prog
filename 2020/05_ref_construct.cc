#include <cstring>
#include <string>
#include <list>
#include <map>
#include <iostream>

using namespace std;
// test drive
class Base {
  public:
    Base() {
      cout << "base::Base()" << endl;
    }
    
    Base(const Base &b) {
      cout << "base::Base(const Base &b)" << endl;
    }

    Base(Base && b) {
      cout << "base::Base(Base && b)" << endl;
    }
};

int main (int argc, char * argv[])
{
  Base b1;
  Base &refb = b1;

  Base b2(refb);
  return 0;
}
