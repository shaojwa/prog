```
readelf -d /usr/lib64/samba/libldbsamba-samba4.so | grep NEEDED 
```

#### the version of lib
```
readelf /usr/lib64/samba/libldbsamba-samba4.so --version-info
```
