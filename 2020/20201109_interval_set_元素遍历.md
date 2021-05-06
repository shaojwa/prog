#### interval_set 的元素遍历
用两层循环：
```
for (interval_set<snapid_t>::iterator i = p.begin();  i != p.end(); ++i) {
  for (snapid_t snap = i.get_start(); snap != i.get_len() + i.get_start(); ++snap) {
    vector<hobject_t> hoids;
    int r = snap_mapper.get_next_objects_to_trim(snap, 1, &hoids);
  }
}
```
