PageCache是一种机制，注意Cache不代表只有读加速，Cache也支持写加速。
```
[wsh@li984-80 ~]$ free
              total        used        free      shared  buff/cache   available
Mem:         838276      253344      102196       40340      482736      411620
Swap:       2097148       10336     2086812
```
在ubuntu下：
```
root@ubuntu-gerrit:/etc/ldap# free
             total       used       free     shared    buffers     cached
Mem:     133981720  117636288   16345432        104    1026312  104300384
-/+ buffers/cache:   12309592  121672128
Swap:      8384508     123952    8260556 
```
在2.2内核之前，有两个cache： PageCache , BufferCache。2.4内核之后，就合并成一个。
读写都会进入buffer/cache， 这个就是PageCache。
