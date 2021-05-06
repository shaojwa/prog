#### reinterpret_cast
```
// slabs[index].slab_data.c_str() returns char *
auto pslab = (unsigned char *)(slabs[index].slab_data.c_str()); // success
auto pslab = static_cast<unsigned char *>(slabs[index].slab_data.c_str()); // fail
```

按照cppreference的说法，reinterpret_cast不会编译为任何的CPU指令，除非是int和pinter之间的转换。
这是一个存编译期指令，当编译器把原类型当做新的数据类型。这个转化和const_cast很像。

#### static_cast
原先的理解是，static_cast是会改变原有表达式的值，他需要能把原有的内存数据进行转化，reinterpret_cast不会做这个转化。
stroustrup告诉我们(https://www..com/bs_faq2.html#static-cast)，类型转换在一般情况下最好避免，

#### 总结
Converting an char to an unsigned char is a conversion. Converting char * to unsigned char* and then reading the elements assuming
that they have been converted when they haven't is very different.

char* 到 unsigned char* 是，对象的值是一样的，只是类型不同。而char to unsigned char，返回内存二进制表达已经不一样。比如float到double。
