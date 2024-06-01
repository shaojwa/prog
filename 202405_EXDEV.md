EC库函数中，有一部分逻辑是对比版本，如果版本不匹配，就返回这个错误码，那这个错误码是什么意思？
## 报错信息
## error code EXDEV
Cross-device link 意思是什么，其中的一个场景是不同文件系统之间创建硬链接，即跨设备的链接（跨越文件系统边界）。

## 不知道为什么连接EC库版本不对
不确认，这种场景下，为什么也是这个错误， 这个修改的标题是：
```
erasure-code: add Ceph version check to plugins.

Add the __erasure_code_version function to all plugins, to return the
Ceph version against which they have been compiled. When a plugin is
loaded, an error is thrown if the version of the plugin does not match
the version of the daemon loading it.

If the symbol does not exist, which whill be true of older plugins, set
the version to "an older version" so it never matched

https://tracker.ceph.com/issues/9176 Fixes: #9167
```
