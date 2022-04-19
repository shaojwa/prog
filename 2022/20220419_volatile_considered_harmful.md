https://www.kernel.org/doc/html/latest/process/volatile-considered-harmful.html
```
spin_lock(&the_lock);
do_something_on(&shared_data);
do_something_else_with(&shared_data);
spin_unlock(&the_lock);
```


https://lwn.net/Articles/233482/
```
The spinlock primitives act as memory barriers.
If shared_data were declared volatile, the locking would still be necessary.

If the memory barriers are right, then the "volatile" doesn't matter.
And if the memory barriers aren't right, then "volatile" doesn't help.
```

The problem with volatile in a multithreaded context is that it doesn't provide all the guarantees we need.
It does have a few properties we need, but not all of them, so we can't rely on volatile alone.
