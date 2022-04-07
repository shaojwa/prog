一个IO的blocking与否，到底和什么相关？最直接的两个因素：是fd，还是interface（read/write）?

#### 接口可决定blocking与否么？
我觉得是显然的，read()当然是可以不阻塞的，什么条件？ fd以O_NONBLOCK模式打开，也就是调用open() 的时候，加上O_NONBLOCK。
看来接口的阻塞不阻塞，最终还是打开的时候，设置的fd属性有关系。

#### 根据epoll的man页面，似乎fd还有这个属性
```
with nonblocking file descriptors
```
