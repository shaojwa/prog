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
