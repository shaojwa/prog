`~`这个运算符，就是`bit-level`的运算之一，我们对关心的是，只是写一个数字，这个数字默认是多大的带宽？只是一个数值，默认是32bit。
但是会根据数值的大小，选择合适的type，比如：
```
(gdb) ptype 100
type = int
(gdb) ptype -100
type = int
(gdb) ptype 111111111
type = int
(gdb) ptype 1111111111
type = int
(gdb) ptype 11111111111
type = long long
(gdb) ptype 4111111111
type = unsigned int
(gdb) ptype 2111111111
type = int
(gdb)
```
