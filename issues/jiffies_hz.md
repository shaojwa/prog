jiffies 值的获取，iffies的初始值并不是0，而是300s后即将溢出的的值。这是为了存在溢出问题的情况下，尽早暴露问题。

http://books.gigatux.nl/mirror/kerneldevelopment/0672327201/ch10lev1sec3.html

#### 正确方法

```
$ grep 'CONFIG_HZ=' /boot/config-$(uname -r)
```

#### 错误方法

```
$ getconf CLK_TCK
100
```
getconf CLK_TCK aka sysconf(_SC_CLK_TCK) returns USER_HZ aka CLOCKS_PER_SEC.
