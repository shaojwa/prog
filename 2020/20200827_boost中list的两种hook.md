boost对intrusive list 有两种hook，分别叫 base hook 和 member hook，有什么区别呢？分别的使用场景是什么？

ceph中，用member hook场景远远比 base hook多。member hook的用法和 内核中的list非常类似，自定义的类不需要继承自list_base_hook，只需要在类中加上类似的一个`boost::intrusive::list_member_hook<> queue_item;` 就可以。

而base hook的常见用法是`class MyClass : public list_base_hook<> {};`
