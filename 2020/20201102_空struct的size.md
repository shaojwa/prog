在C中空结构体的大小是0，但是在C++中空结构体的size是1，为什么？

因为在C中，空的结构体并不允许，gcc扩展了语法，所以才支持。但是具体多少并没有定义，因为C99中有写：
```
If the struct-declaration-list contains no named members, the behavior is undefined.
```
http://www.cantrip.org/emptyopt.html
