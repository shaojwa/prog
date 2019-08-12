
#### vim 中insert模式下backspace无效

搜一下看到说是backspace为空导致，正常情况下是backspace=indent,eol,start，表示可以删除indent，eol
  
8.0以后，如果没有user vimrc，才会把backspace设置为indent,eol,start，否则为空。

查看版本为 version 8.1.1777，将 .vimrc文件改名后，backspac而恢复正常。

