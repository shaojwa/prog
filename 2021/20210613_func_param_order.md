函数中参数的循序，特别是构造函数，比如`rcache_object_t`类的构造函数：
```
rcache_object_t::rcache_object_t(
  const object_t &obj_id,
  const string &nspce,
  rcache_hash_node_t *hash_node) {
  }
 ```
 其中，hash_node是依赖成员，在类的定义中，放在比较开头的问题，但是函数参数中，放在第一个似乎不太合适，毕竟只是依赖关系。
 而nspace，从逻辑上来说，这个obj是在这个nspace中的，似乎nspace，也应该在obj_id之前？但是似乎也不合理，毕竟这个接口是用来创建object。
 所以，现在的原则是，函数的主要操作对象，放在第一个参数中，接着放和这个对象强相关的参数，依赖项可以放在最后面。
