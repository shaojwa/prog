在遍历bufferlist的时候，获取buffferptr对应数据长度时，常用的办法是：
```
bufferlist::const_iterator it = bl.begin();
bufferptr ptr;
ptr = it.get_current_ptr();
```
中间需要有个临时的ptr，似乎不是很简洁，或者连着写：
```
it.get_current_ptr().length();
```
