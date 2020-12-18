https://en.cppreference.com/w/cpp/language/destructor
#### =default的用法
强制编译器生成特定的析构函数

#### =delete的用法
禁用隐式的析构函数

#### 什么时候调用
* 对于静态对象，在程序终止时调用。
* 对于线程局部对象，在线程对出时调用。
* 对于自动变量或者因为引用绑定而导致生命延长的临时变量，在作用域结束时调用。
* 对于匿名临时变量，在表达式结束时调用。
* 对于动态申请空间，在delete表达式执行时调用。
* 湛展开（stack unwinding）

#### 什么是 Prospective destructor
一个类一般有多个潜在的析构函数，此时重载决议（overload resolution）就会执行，如果决议失败，那么就会报告ill-formed。

#### 编译器声明的析构函数
如果不提供用户定义的析构函数，那么编译器就会声明一个（declare），注意两点：
1. 是没有人任何的用户自定义析构函数，而不是没有无参的用户自定义析构函数。
1. 只是声明。

#### 隐藏式申明的析构函数
Implicitly-declared destructor，有两个特点：
1. public
1. inline
1. non-throwing 
隐式声明的析构函数和其他特定的隐式声明的析构函数一样，都是noexcept的。

#### 删除隐式声明的析构函数
从C++11开始，隐式声明的析构函数被定义为delete（c++11之前是未定义），只要一下条件中的一条满足：
1. class-T 中的谋个非静态成员无法被析构，比如析构函数定义为deleted或者析构函数不可访问。
1. class-T 中的直接基类或者某个虚基类无法被析构。
1. class-T是union类型，而且其中的某个成员有non-trivial析构函数。
1. 隐式析构函数是virtual并且在找deallocate-fun的时查找到一个deleted或者不明确的，或者无法访问到的函数。

#### trivial析构函数
如果下面的所有条件都满足，那么这个析构函数就是trivial析构函数：
1. 没有用户自定义的析构函数
1. 这个析构函数non-virtual
1. 直属基类有trivial析构函数
1. 类中所有的非静态成员都有trivial析构函数
trivial析构函数不会采取什么行动，不需要delete表达式，只是简单的释放他们的存储空间。

####  显示定义的析构函数
Implicitly-defined destructor，隐式申明的析构函数如果没有被delete，那么它就会被隐式定义。

#### 析构顺序
1. 先调用析构函数
1. 然后调用成员的析构函数
1. 然后调用直属非虚子类的析构函数

#### 虚析构
#### 纯虚析构

#### 什么时候需要提供空的析构函数
https://www.codesynthesis.com/~boris/blog/2012/04/04/when-provide-empty-destructor/
如果我自定义了一个空类，那么派生类就一定会生成一个析构函数的定义。
