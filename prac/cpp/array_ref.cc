#include <iostream>
using namespace std;

class Dog {
  int _age;
  public:
  Dog() = default;
  Dog(int age): _age(age) {} 
  int get_age() {
    return _age;
  }
  void set_age(int age) {
    _age = age;
  }
};

constexpr int num = 10;

int main() {
  Dog dogs[num];
  for (int i = 0; i < num; i++) {
    cout << dogs[i].get_age() << endl;
  }
  for (int i = 0; i < num; i++) {
    dogs[i].set_age(i);
  }
}
