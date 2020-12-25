
#include <iostream>
#include <string>
using  namespace std;

class Dog {
  int age;
  string name;
  public: 
  Dog(int age_) : age(age_) {}
  int get_age() { return age;}
};

void func_ref(Dog &d) {
  cout << __func__ << " d.age " << d.get_age() << endl;
  cout << __func__ << " addr(d) " << &d << endl;
}

void func_inst(Dog d) {
  cout << __func__ << " d.age " << d.get_age() << endl;
  cout << __func__ << " addr(d) " << &d << endl;
}

int main() {
  int a = 10;
  cout << "&a " << &a << endl;
  int &b = a;
  cout << "&b " << &b << endl;
  auto &c = b;
  cout << "&c " << &c << endl;
  Dog dog(2);
  cout << "addr dog " << &dog << endl;
  func_ref(dog);
  func_inst(dog);
 }
