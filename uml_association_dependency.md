https://cloud.tencent.com/developer/article/1176331

依赖关系很弱，所以是虚线箭头，关联关系略强，是实线箭头。
如果是两个对象生命期完全不相关的，可以用依赖，比如只是类的接口中，用到另外一个类的实例做参数。

如果有一定关系，比如实例化的时候产生，对象销毁的时候关系结束，那多半是关联关系，特别是如果一个类有一个指向另外一个类的指针，那么这种基本都是关联关系。
两个类之间有固定的连接，所以叫关联关系。
