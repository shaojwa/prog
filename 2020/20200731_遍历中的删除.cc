```
for (set<SnapRealm*>::iterator p = open_children.begin(); p != open_children.end(); )
{
    SnapRealm *realm = *p;
    if (realm != child)
    {
      open_children.erase(p++);
    }
    else
    {
      ++p;
    }
  }
```
