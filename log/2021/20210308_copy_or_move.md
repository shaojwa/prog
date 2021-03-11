#### 如果copy构造函数（常量左值引用）和移动构造函数（右值引用）都可用的情况下，rvalue作为参数时，该用哪个？

这个问题涉及到rvalue类型5条属性中的最后一条：当rvalue作为一个函数的参数时，如果函数有两种重载方式，一种是，右值引用，另外一种是常量左值引用(原文：lvalue reference to const)，那么这个rvalue会绑定到 rvalue reference。

其实这个问题是因为c++11引入xvalue才有的问题，因为xvalue，多了两个默认的成员函数，move构造和move复制，和原先的copy构造和copy赋值对应起来。
就是因为有了两种选择，导致需要引入决议规则，即，如果copy构造函数（常量左值引用）和移动构造函数（右值引用）都可用的情况下，那么rvalue参数会调用move构造函数。
类似的赋值运算符，如果有copy赋值和move赋值，那么参数是rvalue的情况下，会用move赋值。
