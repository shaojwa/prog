SIGKILL和SIGSTOP是不能被设置handler的，也就是不能被catch,也不能被ignore，函数调用会返回22错误。
```
wsh@li984-80 testcode]$ make run
pid 3235464, sig_sethdl, signal signum 9 fail, errno is 22
pid 3235464, sig_sethdl, signal signum 19 fail, errno is 22
pid 3235464, sig_sethdl, signal signum 2 done, ph 0
pid 3235464, sig_ign, ign signum 9 fail, errno is 22
pid 3235464, sig_ign, ign signum 19 fail, errno is 22
pid 3235464, sig_ign, ign signum 2 done, pg 1
```
22 就是 EINVAL。
