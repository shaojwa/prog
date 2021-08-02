如何编写更好的代码，这是每一个程序员的最高追求。

## 编码准则
#### 每一行代码都考虑放在什么地方最合适
every line of code should in the best place of the code-tree
we know that program should be designed in levels from top down in logic.

#### 每一个功能都需要考虑在什么模块中实现最合适
find most suitable object to do the work, the best object, in which the code placed.

#### 代码首先在逻辑上是严密的
一个功能代码，首先必须在逻辑上是严密的，不要编写逻辑上已经不严密的代码。
写代码时，尽可能多得猜想各种可能性，然后处理每一种可能性，逻辑上没有漏洞。

## 类的设计
## 函数设计
#### 尽量设计返回值为空的函数
void function make the code concise and clean


## 流程控制

#### 销毁函数(destroy)或者关闭函数(shutdown) 要设计成幕等来避免副作用
shutdown/destroy function should be called multiple times without side effects.

#### should we define the up-level pointer first in calss?
#### what is the order of member-field and member-function?
#### should we assign the value of enum-field explicitly?
#### think about bit-field when anytime state-machine in need
```
union obj_state_t {
  struct {
  uint8 clean:1;
  uint8 dirty:1;
  uint8 filling:1;
  uint8 destage:1;
  };
  uint8 val;
  obj_state_t(uint8 v = 0 ): val(v) {}
  operator uint32() const { return uint32(val); }
};
```

### empty destructor is ok?
generally speaking, empty destructor is not appropriate.
empty destructor causes the destructors of the derived-class be generated forcelly, which cause the meaningless function calls.

#### using inline functions
we should keep in mind that inline-function is critical to the preformance.

#### assert
using **assert** in need, especially in scenarioes of invalid code branches.

#### error handling

#### avoid assert-abuse
remove asserts not in need, same to exceptions-handles.

#### using 0 as the return value without a macro
it is ok in my opinion.

#### the position to declare the variable in c++
declaring the variable just before the place in use.

#### using nullptr instead of NULL in c++
```
MDSRankDispatcher *mds_rank = nullptr;
// tick and other timer fun
Context *tick_event = nullptr;
class MDSSocketHook *asok_hook = nullptr;
```

#### the style of testing zero
AsyncConnection.cc in ceph use the simplest way like follows:
```
unsigned middle_len = current_header.middle_len;
if (middle_len) {
}
if (!middle.length())
}
```
avoid using 'middle_len == 0' or 'middle_len != 0'

#### using this in self-class initialization list
using this in constructor is allowed, refer to MDSRank::MDSRank：
```
DataManager::DataManager():
_dm_lock("dm::_dm_lock"), 
_dm_state(DM_STATE_NONE),
_cache_table(new dm_hash_table_t(this)) {}
```

#### setting member-pointer to nullptr is not in need in destructor.
in destructor, we using delete to free the memory pointed by the member-pointer.
after deleting, it is not in need to setting the member-pointer to nullptr.
but before deleting, we should check if the pointer is nullptr.
please refer to the class InoTable.

#### not check to the return value of operator new()
```
// start mds
mds = new MDSDaemon(g_conf()->name.get_id().c_str(), msgr, &mc, ctxpool);
```


## 日志设计
#### 日志首先是完备的
一行日志，必须能反应当前状态的关键信息，以明显区别别处的日志。
写日志时，要时时考虑到当前时刻，可能出什么问题，需要什么日志来协助定位。

#### 日志是尽量精简的
日志时精简的的，一个函数内不应该出现对一个对象的多次打印，除非这个对象的值发生变化。
有时候为了方便过滤，而有重复打印一个变量的需要，但是这不是必须的，还是应该尽量不要打印重复的信息。
