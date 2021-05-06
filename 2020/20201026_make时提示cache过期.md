```
Your cache is probably stale. Please remove the entry
  dcache-dm_LIB_DEPENDS
from the cache.
```
原因是之前dcache-dm是一个库，dcache-dm-test需要依赖这个库，后来编译dcache-dm-test时不再依赖，但是cmake缓存没有更新，就会导致这个错误。
