https://stackoverflow.com/questions/6438086/iterator-invalidation-rules

#### 这涉及到一个 rule
这个rule叫，Iterator invalidation rules，简单来说就是，容器的erase一般会导致指向删除元素的iter失效。

#### 原先的安全写法
在以前，确实是需要先让it++，确实需要这么写：
```
for (auto it = _cold_queue.begin(); it != _cold_queue.end(); ) {
  if ((*it)->read_count >= _conf_warmq_count_threshold)
  {
    auto iter = it++;
    _cold_queue.erase(iter);
    continue;
  }
  it++;
}
````

#### erase的改进
C++11之后，erase会返回下一个迭代器，所以现在不需要自增。
```
for (auto it = _cold_queue.begin(); it != _cold_queue.end(); ) {
  if ((*it)->read_count >= _conf_warmq_count_threshold)
  {
    it = _cold_queue.erase(iter);
    continue;
  }
  it++;
}
```
