析构函数来判断是否需要释放空间。bufferptr是一个含简单的结构，里面有一个raw指针。
这个指针指向的空间是否释放，要看这部分空间的引用是否为0，所以bufferptr析构没关系，这个ptr指向的空间不释放就行。
```
 void buffer::ptr::release()
  {
    if (_raw) {
      bdout << "ptr " << this << " release " << _raw << bendl;
      if (--_raw->nref == 0) {
        ANNOTATE_HAPPENS_AFTER(&_raw->nref);
        ANNOTATE_HAPPENS_BEFORE_FORGET_ALL(&_raw->nref);
	      delete _raw;  // dealloc old (if any)
      } else {
        ANNOTATE_HAPPENS_BEFORE(&_raw->nref);
      }
      _raw = 0;
    }
  }
 ```
