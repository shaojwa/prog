#### C++中类成员函数的汇编代码常见的如下：
```
push   %r15
push   %r14
push   %r13
push   %r12
push   %rbp
mov    %rsi,%rbp
push   %rbx
mov    %rdi,%rbx
sub    $0x138,%rsp
```
对应的源代码是：
```
void RCache::_enqueue_warm(rcache_object_t &obj)
{
  dout(3) << __func__ << " obj_id " << obj.obj_id
    << ", space " << obj.used_space << dendl;
  obj.queue_id = RCACHE_QUEUE_WARM;
  _lock_queue(RCACHE_QUEUE_WARM);
  _warm_queue.push_back(obj);
  _unlock_queue(RCACHE_QUEUE_WARM);
  _inc_stat(RC_STAT_WARM_SPACE, obj.used_space);
  _lru_warm();
}
```
为什么要这样？

#### 一般情况下的成员函数汇编代码是

1. 保存原有栈底寄存器: `push %rbp`
2. 用当前的栈顶做栈底: `move %rsp, %rbp`
3. 存放函数参数，在C++中，成员函数调用按照thiscall的调用约定，参数是在函数内push的。
4. 申请局部变量空间: `sub nnn($rsp)`

#### 为什么这个函数一开始这么多push？

#### 为什么这个函数没有 `move %rsp %rbp` 


