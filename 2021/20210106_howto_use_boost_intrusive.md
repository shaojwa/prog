https://www.boost.org/doc/libs/1_55_0/doc/html/intrusive/usage.html
#### 侵入式容器的类
一个类，如果打算放入到侵入式容器中，这个类需要额外的一些数据成员。类中需要的这些成员一般叫hook，

#### 两种hook
1. base-hook，目标class继承自hook类
1. member-hook

#### base-hook
基类的语法就是is-a结构
语法：
```
class Foo: public list_base_hook<>
```
用这种hook时，如果你希望这个对象在多个变表中，那么需要继承自多个base-hook，且需要用tag区别开来。比如：
```
typedef list_base_hook< tag<hash> > HashBaseHook;
typedef list_base_hook< tag<lru> > LruBaseHook;
class Foo   :  public HashBaseHook, public LBaseHook
{ /**/ };
typedef list< Foo, base_hook<HashBaseHook> > HashList;
typedef list< Foo, base_hook<LruBaseHook> > LruList;
```

#### member-hook
有时候，is-a的结构不适合，所以此时用成员类型的就更加合适：
1. 先在class中添加字段
1. 用添加的字段定义list类型
我个人的看法是，这种定义似乎比较麻烦，没有继承基类来得干净，至少class中没有明显的专用成员字段。

#### 两种都用

#### earse
1. using unlink() // https://www.boost.org/doc/libs/1_35_0/doc/html/intrusive/erasing_and_disposing.html


#### 用例
```
struct rcache_object_t : public boost::intrusive::list_base_hook<>
{
  CephContext *_cct;
  RCache *rcache;
  rcache_hash_node_t *hash_node;
  RWLock object_rwlock;
  object_t obj_id;
  uint64 read_count;
  uint64 used_space;
  uint8 queue_id;
  map<snapid_t, rcache_objsnap_t *> object_snaps;

public:
  rcache_object_t(const object_t &obj_id_, RCache *rcache_, rcache_hash_node_t *hash_node_);
  void clear();
  rcache_objsnap_t* get_object_snap(snapid_t snap_id, bool create);
  inline void inc_space(uint64 delta)
  {
    used_space += delta;
    hash_node->inc_space(delta);
  }
  inline void dec_space(uint64 delta)
  {
    used_space -= delta;
    hash_node->dec_space(delta);
  }
};
typedef boost::intrusive::list<rcache_object_t> blist_obj_t;
```

#### ceph 用例
```
switch (b->cache_private) {
case BUFFER_WARM_IN:
  warm_in.erase(warm_in.iterator_to(*b));
  break;
case BUFFER_WARM_OUT:
  warm_out.erase(warm_out.iterator_to(*b));
  break;
case BUFFER_HOT:
  hot.erase(hot.iterator_to(*b));
  break;
default:
  ceph_abort_msg("bad cache_private");
}
num = hot.size() + warm_in.size();
```
