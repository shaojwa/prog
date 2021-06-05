我们可以在`.gdbinit`中设置**breakpoint**，尽管这不是最好的方式。最好的方式是定义**breakpoint**的专有文件，然后在`gdb attach`之后，用`source`命令加载。

####  优点和缺点
但是写在`.gdbinit`中的好处是，gdb运行时自动加载。缺点是，因为此时symbol还没有记载，那些通过函数名指定的breakpoint是找不到的，所以会有错误。
`Make breakpoint pending on future shared library load? (y or [n]) [answered N; input not from terminal]`

#### 解决方案
通过错误信息我们也能看到，只要想办法同意`pending`就可以解决问题，那么需要在`.gdbinit`文件中添加`set breakpoint pending on`解决问题。
