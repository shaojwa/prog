http://wiki.dwarfstd.org/index.php?title=Path_Discriminators

#### 示例
```
src/dse/dcache/dm/dm.cc:2050 (discriminator 2)
  ad825a:       4c 8d a4 24 50 02 00    lea    0x250(%rsp),%r12
  ad8261:       00
  ad8262:       48 89 de                mov    %rbx,%rsi
  ad8265:       48 83 05 1b 00 25 01    addq   $0x1,0x125001b(%rip)        # 1d28288 <__gcov0._ZN12dm_objsnap_t19snap_write_fragmentERK9hobject_ttyyRKN4ceph6buffer4listE+0x10c8>
  ad826c:       01
  ad826d:       4c 89 e7                mov    %r12,%rdi
  ad8270:       e8 bb b5 de ff          callq  8c3830 <interval_set<unsigned long long>::interval_set(std::map<unsigned long long, unsigned long long, std::less<unsigned long long>, std::allocator<std::pair<unsigned long long const, unsigned long long> > >&)@plt>
  ad8275:       48 83 05 13 00 25 01    addq   $0x1,0x1250013(%rip)        # 1d28290 <__gcov0._ZN12dm_objsnap_t19snap_write_fragmentERK9hobject_ttyyRKN4ceph6buffer4listE+0x10d0>
  ad827c:       01
map():
/usr/include/c++/4.8.2/bits/stl_map.h:181 (discriminator 2)
```
