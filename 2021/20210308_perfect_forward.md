#### 背景
封装函数fun收到一个右值引用，但却无法在func中调用其他右值引用的函数，因为func中参数的具名导致参数本身变成了左值，无法继续掉以右值为参数的函数。
```
template<typename T>
T&& forward(T&& a) {
  return static_cast<T&&>(a);
}
```
使用
```
template <class T>
void fun(T&& rhs) {
    process(forward(rhs));
}
```
rhs是右值引用到一个对象，也就是可以从rhs指向的对象中偷东西。但是rhs本身却不能被右值引用，也就是说不能有新的引用指向rhs，从rhs中偷东西。
所以，process只能调用左值引用的版本，无法调用右值引用的版本，或者说，只能在fun中头转移匿名对象的数据，不能从process中转移匿名对象中的数据。

#### 完美转发为目标
```
如果参数是右值引用，则返回右值引用
如果参数是左值引用，则返回左值引用
```
#### 本质上完美转发是对参数的作用

让参数不再携带左值属性。

#### 完美转发的实现
```
template<typename T>
T&& forward(T&& a) {
  return static_cast<T&&>(a);
}
```
