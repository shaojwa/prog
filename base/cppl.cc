
#include "cppl.h"
#include <iostream>
#include <cstddef>
#include <typeinfo>
#include <vector>

using namespace std;


//  a[n] is lvalue when a is lvalue
int* address(int a[], int n) {
  int *addr = 0;
  addr = &(a[2]);
  return addr;
}

//
// string_literal is lvalue
int str_literal() {
  const char (*straddr)[12] =  &("str_literal");
  const char *pstr = "str_literal";
  cout <<  straddr << ", pstr " << static_cast<const void *>(pstr) << endl;
  return 0;
}


  template<class T>
constexpr T clone(const T& t)
{
  return t;
}

void g(int*)
{
  std::cout << "Function g called\n";
}

void nullptr1() {
  g(nullptr); // File
  g(NULL); // File
  g(0); // File
  clone(nullptr); // Fine
  clone(NULL);  // Fine
  clone(0); // Fine
  g(clone(nullptr));
  // g(clone(NULL)); // error: invalid conversion from ‘long int’ to ‘int*’
  g(clone((int*)0)); // Fine
}


int sol(int n) {
  return n;
}

int* sol(int* n) {
  return n;
}


void type_sulution() {
  sol(0);
  // sol(NULL); // overloaded ‘sol(NULL)’ is ambiguous
}

class Animal {
  public:
    Animal(string name, int age): _name(name), _age(age) {
    }
    string get_name() { 
      return _name;
    }
    int get_age() { 
      return _age;
    }
  private:
  int _age;
  string _name;
};

class Dog: public Animal {
  public:
    Dog(): Animal("danny", 0) {
    }
    Dog(string name, int age, string color): Animal(name, age), _color(color) {
      }
    string say_something() {
      return "I'm " + get_name() + ", I'm " + to_string(get_age()) + " years old";
    }
    string get_color() { 
      return _color;
    }
  private:
  string _color;
};

void static_cast1() {
  Dog* pdog = new Dog("danny", 4, "block");
  cout << "dog " << pdog << endl;
  cout << "pet " << static_cast<Animal*>(pdog) << endl;

}

void dynamic_cast2() {
  //Animal* panimal = new Dog();
  //cout << "dog " << dynamic_cast<Dog*>(panimal) << endl; // downcast
  Dog* pdog = new Dog("mike", 2, "white");
  cout << "animal " << dynamic_cast<Animal*>(pdog) << endl; // upcast
}


class B {
  public:
    virtual void do_something() {
      cout << typeid(this).name() << endl;
    }
  private:
    int age;
    string name;
};

class D : public B {
  string color;
};

void dynamic_cast4() {
  B *pb = new D();
  void *pv = dynamic_cast<void *>(pb);
  cout << "pv " << pv << endl; // upcast
}

void dynamic_cast5() {
  //   B *pb = new B();
  //   pb->do_something();
  //   D *pd = dynamic_cast<D *>(pb);
  //   pd->do_something();
  D *pd = new D();
  pd->do_something();
}
class E:public D {
  int level;
};

#define PREFIX_CHAR (0x64)
void print_str() {
  string str({ PREFIX_CHAR });
  cout << str << endl;
}


void run_cpp_cases() {
  //dynamic_cast4();
  //dynamic_cast5();
  print_str();
}

void probe_vector() {
  Dog d("suse", 3, "white");
  std::vector<Dog> dogs(10);
  //std::vector<Dog> dogs(10, d);
  //for (auto& d : dogs_until11) {
  //  cout << d.say_something() << endl;
  //}
}

void probe_explicit() {
  Dog d("suse", 3, "white");
  // std::vector<Dog> dogs = 10;
  std::vector<Dog> dogs(10, d); // explicit vector (size_type count); util c++14
  for (auto& d : dogs) {
    cout << d.say_something() << endl;
  }
}
