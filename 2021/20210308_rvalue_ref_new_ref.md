#### 引用是一种类型 
引用体现的是一个表达式，这个表达式中，有时候会定义一个变量名，有时候没有变量。

#### 右值引用也是一种类型
1. 同引用一样，右值引用也是一种类型，c++0x引入，这是一种新的引用类型。
2. 在表达式中，同样可以有变量名，也可以没有变量名。
3. 各种所谓的type，就是为了描述一种特性，有新的特性，就需要新的类型。

#### 为什么需要右值引用类型
为了解决没有必要的copy操作，以及实现完美转发(perfect-forward),赋值操作右边的值如果是rvalue，那么赋值操作符左边的对象可以偷走(steal)右边对象内的资源。
这样就避免了单独的分配操作，也就是说用来实现move语义。

>> Rvalue references are a new reference type introduced in C++0x that help solve the problem of unnecessary copying and enable perfect forwarding.
When the right-hand side of an assignment is an rvalue,
then the left-hand side object can steal resources from the right-hand side object rather than performing a separate allocation, thus enabling move semantics.
