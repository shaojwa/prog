#### 函数设计
1. 底层函数设计时，没有返回值很正常，没有问题，设计时也可以往这个方向设计。

#### 异常处理
1. 没必要的异常处理去掉，没必要的assert去掉。

#### 构造析构
1. 析构函数中delete指针指向的内存先判断指针是否为空，析构函数中的成员指针不需要赋值为null，参考class InoTable。
1. 构造函数中可以用this指针构造成成员，也可以用new来分类内存给成员，参考MDSRank::MDSRank：
```
DataManager::DataManager():
_dm_lock("dm::_dm_lock"),  _dm_state(DM_STATE_NONE),  _cache_table(new dm_hash_table_t(this)) {}
```
