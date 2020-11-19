#include <cstring>
#include <string>
#include <list>
#include <map>
#include <iostream>

using namespace std;


class Test {
  private: 
    char *_name;
    size_t _len;
    int _age;

    void _init_name(const char *name) {
      _len = strlen(name);
      _name = new char[_len + 1];
      memcpy(_name, name, _len);
      _name[_len] = 0;
    }

  public:
    Test() {
      cout << "Test::Test()" << endl;
      _age = 0;
    }

    Test(const Test& t) {
      cout << "Test::Test(const Test& t)" << endl;
      _age = t._age;
      _init_name(t._name);
    }

    Test(Test&& t) {
      cout << "Test::Test(Test&& t)" << endl;
      _age = t._age;
      _len = t._len;
      _name = t._name;
      t._len = 0;
      t._name = nullptr;
    }

    Test(const char *name, int age) {
      cout << "Test::Test(string name, int age)" << endl;
      _age = age;
      _init_name(name);
    }

    Test& operator=(const Test& t) {
      cout << "Test::operator=(const Test &t)" << endl;
      if (this != &t) {
        _age = t._age;
        _init_name(t._name);
      }
      return *this;
    }

    Test& operator=(Test&& t) {
      cout << "Test::operator=(Test&& t)" << endl;
      if (this != &t) {
        _age = t._age;
        _len = t._len;
        _name = t._name;
        t._len = 0;
        t._name = nullptr;
      }
      return *this;
    }

    ~Test() {
      cout << "Test::~Test()" << endl;
    }

    void show() {
      cout << "name: " << _name << ", age: " << _age << endl;
    }
};


int main(int argc, char* argv[]) {
  Test t1 = Test("tester", 21);
  Test t2 = Test(std::move(t1));
  return 0;
}
