https://blog.csdn.net/liufei_learning/article/details/34808549

## RAII
RAII，翻译过来是 **资源获取就是初始化**。但是这个翻译并不能体现这个词的真正内涵，RAII的好处在于，它提供了资源的一种自动管理方式，
当产生异常，回滚等操作时，都能保证资源被正常释放，就像上一段中说的那样。RAII也是智能指针的原理。

## boost中的 scoped_ptr
这是一种简单的智能指针，通过名字就可以知道，这个智能在一个作用域内使用，出了作用域后，scoped_ptr就会被释放，它所管理的资源也会释放。
原理就是用一个栈上的对象去管理一个堆上的对象。但是这种类型有一个很大的问题就是，它不能共享所有权，也就是说它管理的对象智能由它自己管理。
说的直接点，就是没有引用计数机制。

## boost::scoped_ptr and std::shared_ptr
这是为解决scoped_ptr而引入的，它可以解决对象共享的问题，非常方便，它的实现机制就是通过引用计数。

## weak_ptr
同样，weak_ptr是对shared_ptr局限性的改进，这个局限性就是shared_ptr不支持循环引用，比如父子相互引用.
其实不是说shared_ptr不支持，而是shared_ptr本身的机制决定相互引用时会导致两个对象都不能释放资源，这非常类似于死锁，A依赖（引用）B，B也依赖（引用）A。

为了解决这种死锁问题，我们引入强引用和弱引用。如果一个对象存在一个强引用，比如shared_ptr，那么这个对象就不能销毁。

但是所引用就类似一个普通的指针，它不会影响对象的引用计数，但是它能检测到对象是否已经被释放，这个怎么做到？

比如上面的父子引用，就可以设置一方对另外一方是弱引用，引用可以存在，但是引用的对消可以销毁。

## intrusive_ptr
依然已经有了shared_ptr，那么为什么还需要侵入式的intrusive_ptr？更不用说，非侵入式的智能指针比侵入式的要灵活，那为什么还需要？

要知道原因，我们得先知道shared_ptr的问题，shared_ptr的问题是，引用计数不在对象中，而是在shared_ptr中这会导致一个问题是：
```
int *a = new int(5);
boost::shared_ptr ptr1(a);
boost::shared_ptr ptr2(a);
```
以上代码，ptr2并不知道ptr1页用的a，所以ptr1析构的时候会释放一次a，ptr2析构的时候也会来一次，这就导致重复释放，这是一个陷阱。
但是intrusive_ptr不会有这个问题，intrusive_ptr所用的引用计数有对象自己实现，对象只有一份，这个引用计数就只有一份。

## intrusive_ptr的使用
intrusive_ptr_add_ref 和 intrusive_ptr_release来管理引用计数。
