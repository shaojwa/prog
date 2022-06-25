因为调用vector.resize()而报错的：
```
error: use of deleted function 'std::__atomic_base<_IntTp>::__atomic_base...
...
error: declared here
__atomic_base(const __atomic_base &) = delete;
```
因为 atomic是不支持拷贝构造，需要在初始化的时候就设定好。
