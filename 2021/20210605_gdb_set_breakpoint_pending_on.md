我们可以在.gdbinit中设置breakpoint，尽管这不是最好的方式。因为最好的方式是定义breakppint的file，然后在gdb attach之后，用source命令加载。

####  优点和缺点
但是，在gdbinit中的好处是，gdb运行时自动加载。缺点是，因为此时symbol还没有记载，那些通过函数名指定的breakpoint是找不到的，所以会有以下错误。

#### 解决方案
同意pending就可以解决问题，那么需要在.gdbinit文件中添加```set breakpoint pending on```
