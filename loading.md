#### 共享库的加载路劲


#### 加载问题解决步骤

1. 先看是什么库找不到
```
ldd cephfs.so
```

2. 再看库依赖库查找路径RPATH是否没有包含
```
readelf -d cephfs.so
```

3. 看LD_LIBRARY_PATH中的路径是否正确
```
echo $LD_LIBRARY_PATH
```

#### elf 中的符号查看

3. 如果需要查看ELF中的符号问题用nm
```
nm cephfs.so  | grep openv
```
