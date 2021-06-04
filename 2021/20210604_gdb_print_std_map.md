```
(gdb) p this->chunks
$0 = { 
    _M_t = {
        _M_impl = { <std::allocator<std::_Rb_tree_node<std::pair<unsigned short const, dm_chunk_t*> > >> =
            {<__gnu_cxx::new_allocator<std::_Rb_tree_node<std::pair<unsigned short const, dm_chunk_t*> > >> = {<No data fields>}, <No data fields>},
            _M_key_compare = {<std::binary_function<unsigned short, unsigned short, bool>> = {<No data fields>}, <No data fields>},
            _M_header = {_M_color = std::_S_red, _M_parent = 0x7f9b10600e20, _M_left = 0x7f9b10600e20, _M_right = 0x7f9b10600e20},
            _M_node_count = 1
        }
    }
}
```
got pointer
```
(gdb) p (std::pair<unsigned short const, dm_chunk_t*>*)0x7f9b10600e20
$1 = (std::pair<unsigned short const, dm_chunk_t*> *) 0x7f9b10600e20
```
got map-item
```
(gdb) p *$1
$2 = {first = 1, second = 0x7f9b15d04418}
```
get chunk
```
p *(dm_chunk_t*)0x7f9b15d04418
```
