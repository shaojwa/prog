#### std::move 的实现

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
