#include <iostream>
#include <list>
#include <set>
#include <typeinfo>


using namespace std;

struct Dog {
  Dog(int a): age(a) {
    cout << "Dog(int a)" << endl;
  }
  int age;
  operator int() const {
    cout << "operator int() " <<  endl;
    return age;
  }
};

// #define TEST_LIST

int main () {

#ifdef TEST_LIST
  list<Dog> lst;
  lst.push_back(Dog(1));
  lst.push_back(Dog(2));
  lst.push_back(Dog(3));
  for (list<Dog>::iterator it = lst.begin(); it != lst.end();  ++it) {
    cout << it->age << endl;
  }
  for (Dog &it: lst) {
    it.age = 4;
  }
  for (list<Dog>::iterator it = lst.begin(); it != lst.end();  ++it) {
    cout << it->age << endl;
  }
#else
  set<Dog> s;
  s.insert(Dog(1));
  s.insert(Dog(2));
  s.insert(Dog(3));
  for (set<Dog>::iterator it = s.begin(); it != s.end();  ++it) {
    cout << it->age << endl;
  }
  for (auto &it: s) {
    cout << typeid(it).name() << endl;
    // it.age = 4;
  }
  for (set<Dog>::iterator it = s.begin(); it != s.end();  ++it) {
    cout << it->age << endl;
  }
#endif
  return 0;
}

