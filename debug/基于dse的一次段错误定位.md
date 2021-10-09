#### 先找出函数的在dse中的偏移
我们选用类型是T的地址
```
[root@node125 wsh]# nm /opt/h3c/bin/dse | grep lsm_do_append_retry | c++filt
00000000009fc2b0 T DCacheLineSpaceManager::lsm_do_append_retry(LSM_LOG_INFO*, unsigned int)
```
我们现在知道，段错误所在代码段在dse中的函数起始偏移是 0x9fc2b0 

#### 结合dmesg输出查看代码：
```
[Sat Oct  9 00:06:18 2021] Processer_18[1816266]:
  segfault at 100 ip 000055c57a5fc888 sp 00007f4c3caff960 error 4 in dse[55c579c00000+ea2000]
```
我们知道出现段错误的代码是地址是：000055c57a5fc888，
其中的0x55c579c00000是代码段起始地址：
```
0x55c579c00000 + 0x9fc2b0 = 0x55c57a5fc2b0
```
现在出问题的ip是0x000055c57a5fc888，所以，是在函数内偏移：0x5d8
```
0x55c57a5fc888 - 0x55c57a5fc2b0 = 0x5d8
```
所以对应到汇编代码中的位置是：
```
0x9fc2b0 + 0x5db = 0x9fc888
```

#### objdump得到汇编代码：
```
9fc883:       48 8b 44 24 40          mov    0x40(%rsp),%rax
9fc888:       48 8b 88 e0 00 00 00    mov    0xe0(%rax),%rcx
9fc88f:       48 05 e0 00 00 00       add    $0xe0,%rax
9fc895:       48 39 44 24 48          cmp    %rax,0x48(%rsp)
9fc89a:       48 89 4c 24 08          mov    %rcx,0x8(%rsp)
```
