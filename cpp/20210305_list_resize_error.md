```
#include <iostream>                                         
#include <vector>                                           
using namespace std;                                        
                                                            
#define HASH_TABLE_SIZE 512                                 
                                                            
class hash_node_t {                                         
  public:                                                   
  void *_dm;                                                
};                                                          
                                                            
class hash_table_t {                                        
  public:                                                   
    hash_table_t(void *dm, void *cct): _dm(dm), _cct(cct){};
    void *get_cct() { return _cct; }                        
    void *get_dm() { return _dm; }                          
  private:                                                  
  void *_cct = nullptr;                                     
  void *_dm = nullptr;                                      
  hash_node_t node_set[HASH_TABLE_SIZE];                    
};                                                          
                                                            
int main() {                                                
  vector<hash_table_t> tables;                              
  tables.resize(10);                                            
  return 0;                                                 
}                                                           
```
默认构造函数不存在导致的error:
```
[wsh@localhost code]$ ./make.sh list_resize.cc
last=list_resize.cc ext=cc
compile with g++
In file included from /usr/include/c++/8/vector:62,
                 from list_resize.cc:2:
/usr/include/c++/8/bits/stl_construct.h: In instantiation of ‘void std::_Construct(_T1*, _Args&& .
.) [with _T1 = hash_table_t; _Args = {}]’:
/usr/include/c++/8/bits/stl_uninitialized.h:527:18:   required from ‘static _ForwardIterator std::
_uninitialized_default_n_1<_TrivialValueType>::__uninit_default_n(_ForwardIterator, _Size) [with _
orwardIterator = hash_table_t*; _Size = long unsigned int; bool _TrivialValueType = false]’
/usr/include/c++/8/bits/stl_uninitialized.h:583:20:   required from ‘_ForwardIterator std::__unini
ialized_default_n(_ForwardIterator, _Size) [with _ForwardIterator = hash_table_t*; _Size = long un
igned int]’
/usr/include/c++/8/bits/stl_uninitialized.h:645:44:   required from ‘_ForwardIterator std::__unini
ialized_default_n_a(_ForwardIterator, _Size, std::allocator<_Tp>&) [with _ForwardIterator = hash_t
ble_t*; _Size = long unsigned int; _Tp = hash_table_t]’
/usr/include/c++/8/bits/vector.tcc:596:35:   required from ‘void std::vector<_Tp, _Alloc>::_M_defa
lt_append(std::vector<_Tp, _Alloc>::size_type) [with _Tp = hash_table_t; _Alloc = std::allocator<h
sh_table_t>; std::vector<_Tp, _Alloc>::size_type = long unsigned int]’
/usr/include/c++/8/bits/stl_vector.h:827:4:   required from ‘void std::vector<_Tp, _Alloc>::resize
std::vector<_Tp, _Alloc>::size_type) [with _Tp = hash_table_t; _Alloc = std::allocator<hash_table_
>; std::vector<_Tp, _Alloc>::size_type = long unsigned int]’
list_resize.cc:25:19:   required from here
/usr/include/c++/8/bits/stl_construct.h:75:7: error: no matching function for call to ‘hash_table_
::hash_table_t()’
     { ::new(static_cast<void*>(__p)) _T1(std::forward<_Args>(__args)...); }
       ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
list_resize.cc:14:5: note: candidate: ‘hash_table_t::hash_table_t(void*, void*)’
     hash_table_t(void *dm, void *cct): _dm(dm), _cct(cct){};
     ^~~~~~~~~~~~
list_resize.cc:14:5: note:   candidate expects 2 arguments, 0 provided
list_resize.cc:12:7: note: candidate: ‘constexpr hash_table_t::hash_table_t(const hash_table_t&)’
 class hash_table_t {
       ^~~~~~~~~~~~
list_resize.cc:12:7: note:   candidate expects 1 argument, 0 provided
list_resize.cc:12:7: note: candidate: ‘constexpr hash_table_t::hash_table_t(hash_table_t&&)’
list_resize.cc:12:7: note:   candidate expects 1 argument, 0 provided
```
最后的几个备选构造都发现不行，包括拷贝构造，移动构造，和我们自己定义的默认构造。要让代码中热resize成功运行，需要有无参构造函数。
