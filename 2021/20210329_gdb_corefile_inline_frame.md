#### Why gdb can get the frome of inline-function-call 
```
(gdb) bt
#0  0x00007f5215d4a59b in raise () from /lib64/libpthread.so.0
#1  0x000055d3b9cf2c7a in reraise_fatal (signum=11) at /src/global/signal_handler.cc:76
#2  handle_fatal_signal (signum=11) at /src/global/signal_handler.cc:140
#3  <signal handler called>
#4  _M_data (this=0x58c544c8) at /usr/include/c++/4.8.2/bits/basic_string.h:293
#5  _M_rep (this=0x58c544c8) at /usr/include/c++/4.8.2/bits/basic_string.h:301
#6  size (this=0x58c544c8) at /usr/include/c++/4.8.2/bits/basic_string.h:716
#7  operator<< <char, std::char_traits<char>, std::allocator<char> > (__str=..., __os=...)
    at /usr/include/c++/4.8.2/bits/basic_string.h:2758
#8  operator<< (o=..., out=...) at /src/include/object.h:76
#9  dm_hash_node_t::hn_get_object (this=0x7f4def64ed78, obj_id=..., create=create@entry=true)
    at /src/dse/dcache/dm/dm.cc:990
#10 0x000055d3ba019911 in _dm_locate_object (create=true, obj_id=..., this=0x7f4def0007d0) at /src/dse/dcache/dm/dm.h:597
#11 DataManager::dm_write_obj_data (this=0x7f4def0007d0, hobj=..., oper=..., data=...) at /src/dse/dcache/dm/dm.cc:160
```
