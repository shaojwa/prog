`c++`中表示一个范围都是用半闭半开区间，比如`[first, last)`，所以：

当`range.lower_bound(key)`本意是取一个以key作为下界的range的子集`[range.lower_bound(key), last)`
所以，`lower_bound(key)` 得到的是要第一个大于等于key的。

相同的道理，`upper_bound(key)`得到的是一个以key作为上界的子集`[first, upper_bound(key))`
所以，`upper_bound(key)`需要返回的是第一个大于key的位置，而不是最后一个小于等于key的位置。
因为这里的区间用半开半闭区间来表示的。
