#### 表达式
表达式包括：变量，字面值，等等。

#### 类型和类别
任何表达式都有两个属性，一个是type，一个是value category，我们一般翻译为类型和值类别。

#### 值类别
注意这里不是值类型，而是值类别，类别分左值右值，细分有几类呢？
(1) 比如命名变量，这肯定是左值。
(2) 比如字面值，这肯定是右值，但是也许不只是右值。
那么，const 类型的变量算什么，contexptr 表达式算什么，临时匿名值，比如临时构造传入函数的实参数算什么？ 我们来细细分类。

#### 一开始，我们想到的就是左右
所以简单来说就是，值分左右，但是这个左右分类可以完全穷尽，但是无法相互独立，所以才有需要能相互独立的分类。

#### 相互独立的分类，primary categories
类别有三种，lvalue，prvalue，和xvalue。

1. lvalue，只能在左边，这种类别就是glvalue中除去xvalue的那种，简单说就是这种对象的资源不能复用。
1. prvalue，只能在右边。
1.xvalue，所有都可以，可以在左边的那些 + lvalue 成为glvalue。可以在右边的的那种xvalue + prvalue成为rvalue。

所以我们不要记名字，只要即位置，一种类型有的只能左边，有的只能右边，有的两边都可以。

#### types
* nameless temporaries

#### 生命期的扩展
temporaries whose life was extended by binding to a reference
