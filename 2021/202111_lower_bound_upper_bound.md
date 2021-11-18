`c++`中表示一个范围都是用半闭半开区间，比如`[first, last)`，所以：
当`range.lower_bound(key)`本意是取一个集合`[range.lower_bound(key), last)`
所以，`lower_bound(key)` 得到的是要第一个大于等于key的。
相同的道理，`upper_bound(key)`得到的是一个以key作为上界的集合`[first, upper_bound(key))`
所以，`upper_bound(key)`需要返回的是第一个大于key的位置，因为右边需要的是开区间。
