#### 原因
erase会返回当前删除元素的下一个元素，而这个下一个元素正是当前删除的元素，怎么理解？

以为内reverse_iterator只是iterator的一个adapter，底层的实现其实还是iterator，只是方向想法而已。
所以我们可以通过base接口得到reverse_iterator对应的iterator。
某个迭代器iter转成reverse_iterator之后指向的元素的地址是，这个迭代器前一个元素的地址。
```
&*(reverse_iterator(itr))==&*(itr-1)
```
所以要删除当前的reverse_iterator，其实删除的是这个iterator前面一个元素的，删除之后，iterator还要重新指向前面的这个元素，这就是一个bug。
