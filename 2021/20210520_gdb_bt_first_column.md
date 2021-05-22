stack
```
(gdb) x 0x00005578952acafe
0x5578952acafe <DataManager::do_filling_read(
  hobject_t const&, unsigned short, snapid_t, unsigned short, unsigned long long, unsigned long long)+9310>: 0x48c38948 
```
symbolc
```
[root@hkd92 hc]# nm dse | c++filt | grep do_filling_read
000000000092d6a0 T DataManager::do_filling_read(
  hobject_t const&, unsigned short, snapid_t, unsigned short, unsigned long long, unsigned long long)
```
0x92d6a0 + 0x9310 = 0x9369b0

## what's the meaning of the first column of the bt output
