https://en.cppreference.com/w/cpp/language/implicit_conversion
#### Implicit conversions
隐式转换在cpp中是很常见的一个概念，我们知道一个表达式是有类型的，如果这个表达式的类型是T1，但是这个表达式所在的上下文并不接受（原文是accept）T1这种类型，
但是却接受其他的类型T2，那么就会发生隐式转换，特别是在以下这些场景：

1.  函数调用时，函数声明的类型是T2，但是表达式类型是T1
2.  当表达式被用作一个操作符的操作数时，这个操作符接受T2类型的操作数，但是表达式类型是T1
3.  当初始化一个T2类型的对象时，用T1类型的对象去初始化，或者在函数返回时，函数返回值类型是T2，但是return 表达式类型是T1
4.  在switch语句中，T2是整形，但是T1可能是别的类型。
5.  在if语句或者loop语句中，语句希望T2是bool，但是表达式可能是别的类型，比如int，比如类型的指针等等。

想要程序正常生成，或者说编译通过，那么必须存在一种没有歧义的隐式转换，把T1转换为T2。

如果隐式转换建立后，依然后多个重载函数，或者重载运算符被调用，那么重载决议规则决定，该调用哪个重载函数，或者重载运算符。

注意，在算术表达式中，二元操作符里的操作数在进行隐式转换时，目标类型由一组独立的规则决定，
这规则是[usual arithmetic conversions](https://en.cppreference.com/w/cpp/language/operator_arithmetic#Conversions)
