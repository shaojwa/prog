boost/intrusive/set.hpp
```
 iterator erase_and_dispose(const_iterator i, Disposer disposer)
 {
    node_ptr to_erase(i.pointed_node());
    ++i;
    node_algorithms::unlink(to_erase);
    this->priv_size_traits().decrement();
    if(safemode_or_autounlink)
       node_algorithms::init(to_erase);
    disposer(this->priv_value_traits().to_value_ptr(to_erase));
    return i.unconst();
 }
```
