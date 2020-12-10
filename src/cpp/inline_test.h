
#include<string>
using namespace std;

string foo();
string bar();

class Dog {
  public:
    Dog(const string &name):name(name) {}
    inline string get_name();
    string name;
};

string Dog::get_name() {
  return name;
}
