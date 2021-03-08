#### 完美转发的要求
```
如果参数是右值引用，则返回右值引用
如果参数是左值引用，则返回左值引用
```

#### 完美转发的实现
```
template<typename T>
T&& forward(T&& a) {
  return static_cast<T&&>(a);
}
```
