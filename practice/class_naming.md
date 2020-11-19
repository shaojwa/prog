#### base-class naming
```
$ egrep "class.+\w+Base {" -rn mds | awk '{print $(NF-1)}' | sort | uniq
InodeStoreBase
MDSInternalContextBase
MDSIOContextBase
MDSLogContextBase
```
