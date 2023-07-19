delete释放栈变量地址会怎么样？
```
Jul 19 15:16:31 li984-80 kernel: delete_stack[1867409]:
  segfault at 7ffd90000000 ip 00007f14ecd92b23 sp 00007ffd92d229e0 error 4 in libc-2.28.so[7f14ecd0d000+1b9000]

Jul 19 15:16:31 li984-80 kernel: Code: a8 02 75 3b 48 8b 15 64 62 33 00 64 48 83 3a 00 0f 84 a1 00 00 00 48 8d 3d 8a
 70 33 00 a8 04 74 0c 48 89 f0 48 25 00 00 00 fc <48> 8b 38 48 83 c4 10 31 d2 5b e9 be ca ff ff 66 0f 1f 44 00 00 8b

Jul 19 15:16:31 li984-80 systemd[1]: Started Process Core Dump (PID 1867410/UID 0).

Jul 19 15:16:31 li984-80 systemd-coredump[1867411]: Process 1867409 (delete_stack) of user 1000 dumped core.
#012#012Stack trace of thread 1867409:
#012#0  0x00007f14ecd92b23 __libc_free (libc.so.6)
#012#1  0x000000000040084c n/a (/home/wsh/git/prog/code/delete_stack)
#012#2  0x00007f14ecd306a3 __libc_start_main (libc.so.6)
#012#3  0x000000000040075e n/a (/home/wsh/git/prog/code/delete_stack)
```
error 4
