#### private 析构函数的目的
可以避免类型当做 automatic variable，因为调用析构的时候回出错。

#### 如果private 的构造函数加上 = default 是什么意思
```
~A() = default;
```
#### trival or non-trival
objects with trivial destructors don't require a delete-expression and may be disposed of by simply deallocating their storage.

#### 
The destructor defined with = default is trivial in this case.
