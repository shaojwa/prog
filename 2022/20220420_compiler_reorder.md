#### 来自编译器的假设
生成高性能的代码是编译器的工作之一，但是这种优化需要基于一定的假设才能认定是正确的。其中一个假设是：代码是但线程执行，保证单线程安全。


#### 重排的例子
```
int test_reorder(int a, int b) {
    a = b + 1;
    b = 0;
    return a;
}
```
汇编代码：
```
  0:   55                      push   %rbp
  1:   48 89 e5                mov    %rsp,%rbp
  4:   89 7d ec                mov    %edi,-0x14(%rbp)
  7:   89 75 e8                mov    %esi,-0x18(%rbp)
  a:   8b 45 e8                mov    -0x18(%rbp),%eax
  d:   83 c0 01                add    $0x1,%eax
 10:   89 45 fc                mov    %eax,-0x4(%rbp)
 13:   c7 45 e8 00 00 00 00    movl   $0x0,-0x18(%rbp)
 1a:   8b 45 fc                mov    -0x4(%rbp),%eax
 1d:   5d                      pop    %rbp
 1e:   c3                      retq
 ```
 其中：
 ```
  4:   89 7d ec                mov    %edi,-0x14(%rbp)  // 参数放到栈上
  7:   89 75 e8                mov    %esi,-0x18(%rbp)  // 参数放到栈上
 ```
 然后：
 ```
  a:   8b 45 e8                mov    -0x18(%rbp),%eax  // 把 b 放到eax中
  d:   83 c0 01                add    $0x1,%eax         // b + 1 存到 eax中
 10:   89 45 fc                mov    %eax,-0x4(%rbp)   // 把结果放到栈上，应该就是返回值的位置
 13:   c7 45 e8 00 00 00 00    movl   $0x0,-0x18(%rbp)  // 把 b = 0
 1a:   8b 45 fc                mov    -0x4(%rbp),%eax   // 把结果放回到eax 
```
所以，基本都是按照代码的流程在走。如果是O1优化，那么只有：

```
0000000000000000 <_Z12test_reorderii>:
   0:   8d 46 01                lea    0x1(%rsi),%eax
   3:   c3                      retq
```
LEA 指令本来是加载地址用的，0x1(%rsi)代表的是内存地址，0x1是偏移，当然这里，这个值就是我们要求的和。LEA的指令格式是是：
```
RM  ModRM:r/m (r) ModRM:reg (w) // AT&T 格式
```
