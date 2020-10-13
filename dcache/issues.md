1. 类型转换错误：
```
const uint64 QM_DEFAULT_QUOTA_TOTAL = (uint64(4) << 30);
```

2. 数据小于一个slab时怎么处理？

创建一个新的ptr，然后标记起始和结束位置。
