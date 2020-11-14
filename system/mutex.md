### mutex的几个性质

mutex有很重要的一点是，某个线程lock，就得由那个线程unlock。

#### 和semaphore的区别
使用场景不同，mutex解决的是某个资源只能让一个线程访问。semaphore是控制资源的产生和消费，让多个线程可以配合，但并不是为让资源独占使用。
