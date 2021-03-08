#### std::move 的实现
```
#include <iostream>
using namespace std;
template<class T>
class S;

class Dog {
   public:
    Dog() {
      //puts("ctor");
    }
    Dog(const Dog &a) { puts("copy ctor"); }
    Dog(Dog &&a) { puts("move ctor"); }
};

template<typename T>
T&& poor_move1(T& t) {
  return static_cast<T&&>(t);
}

template<typename T>
T&& poor_move2(T&& t) {
  return static_cast<T&&>(t);
}

int main() {
    Dog d1;
    // t is Dog
    Dog d2(poor_move1<Dog&>(d1)); // compile ok

    //
    // t is rvalue of Dog
    // error: cannot bind non-const lvalue reference of type ‘Dog&’ to an rvalue of type ‘Dog’
    // Dog() is rvalue of type Dog
    poor_move2(Dog()); //
    return 0;
}
```

#### 引用坍塌
引用坍塌 Reference collapsing，这是c++11引入的[规则](https://en.cppreference.com/w/cpp/language/reference)：
```
typedef int&  lref;
typedef int&& rref;
int n;
lref&  r1 = n; // type of r1 is int&
lref&& r2 = n; // type of r2 is int&
rref&  r3 = n; // type of r3 is int&
rref&& r4 = 1; // type of r4 is int&&
```
