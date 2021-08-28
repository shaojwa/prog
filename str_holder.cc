#include <iostream>
using namespace std;

class StringHolder {
  public:
    StringHolder(const string &val):val_(val) {}
    const string &get() {return val_;}
  private:
    const string &val_;
};

int main()
{
  StringHolder helder("hello");
  cout << helder.get() << endl;
  return 0;
}
