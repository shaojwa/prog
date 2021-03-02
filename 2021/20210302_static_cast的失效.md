```
// slabs[index].slab_data.c_str() returns char *
auto pslab = (unsigned char *)(slabs[index].slab_data.c_str()); // success
auto pslab = static_cast<unsigned char *>(slabs[index].slab_data.c_str()); // fail
```
