#### 返回指针还是引用
很多时候，我们会走极端，也许某一段时间，我们觉得引用很好，所以能用引用的地方都用引用，特别是在C++中。
所以，也许我们会尝试把函数的返回值变成引用，一般这是没问题的，但是有的场景下用引用就不方便，比如：
如果这个函数的返回值并不是每次都能成功法返回某个对象，那么这个时候用引用就不方便，因为引用意味着对象一定存在，此时用指针就比引用更合适。
```
rcache_object_t *rcache_hash_node_t::hn_get_object(const object_t &obj_id, bool create)
rcache_objsnap_t *rcache_object_t::get_object_snap(snapid_t snap_id, bool create)
```
这两个接口都有一个create参数，也就是说，有时候找不到会创建，有时候并不会创建，如果不能创建就需要表示找不到。
一般说来，使用nullptr来表示找不到某个对象，此时用引用就不方便表示。
