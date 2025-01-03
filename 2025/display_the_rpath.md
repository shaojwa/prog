displays  the contents of the files's dynamic section
```
readelf -d preload_test
```
or
```
objdump -x preload_test | grep RPATH
```
