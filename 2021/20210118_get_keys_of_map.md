using loop is simple and good:
```
set<snapid_t> snaps;
for (auto it= obj->object_snaps.begin(); it != obj->object_snaps.end(); ++it)
{
  snaps.insert(it->first);
}
f->dump_stream("snaps") << snaps;
```
