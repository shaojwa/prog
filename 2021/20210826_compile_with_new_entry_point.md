#### 程序的主函数是否可以不用main
据说是可以的，需要添加编译选项`-Wl,-etmain`，但是我并没有试验成功。

#### 入口程序
编译时的入口函数是`_start()`, `_start()` 会调用`main()`，但是我们可以替换的是`_start()` 

#### C程序可以，但是cc程序不行
```
gcc -Wall -O0 -g -nostartfiles -Wl,-etmain -o out tmain.cc
```
