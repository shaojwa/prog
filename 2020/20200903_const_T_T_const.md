两者一样，有一个Right-to-Left规则了解一下。
```
void dm_hash_node_t::hn_release_obj(const dm_user_obj_t *user_obj)
同
void dm_hash_node_t::hn_release_obj(dm_user_obj_t const *user_obj)
```
常量指针
```
void dm_hash_node_t::hn_release_obj(dm_user_obj_t * const user_obj)
```
如果赋值那么报错：
```
error: assignment of read-only parameter ‘user_obj’
```
