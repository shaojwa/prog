- [assert](#assert)
- [log](#log)

# design
## using non-void function only in necessary
void function make the code concise and clean

## destroy/shutdown function should be idempotent
shutdown/destroy function should be called multiple times whiout side effects.

## find the best place for each line of code
every line of code should in the best place of the code-tree
we know that program should be designed in levels from top down in logic.

## who should do the work
find most suitable object to do the work, the best object, in which the code placed.

# code
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

# log
## log line should contain one key string at least to track flow
in the op-handling flow of a object, object_id is the key string in log to track all steps of the op.
