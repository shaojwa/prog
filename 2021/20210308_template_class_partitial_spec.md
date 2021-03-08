#### 模板类的定义
模板类，可以生成各种类, 比如有类 remove_reference:
```
template <class _Tp> struct remove_reference{typedef _Tp type;};
template <class _Tp> struct remove_reference<_Tp&>  {typedef _Tp type;};
template <class _Tp> struct remove_reference<_Tp&&> {typedef _Tp type;};

```
偏特化也是模板类的定义，类比std中的list模板类，发现是类似的：
```
template<class T, class Allocator = std::allocator<T>> class list;
```
看list的实现：
```
  void
  push_back(const value_type& __x)
  { this->_M_insert(end(), __x); }

#if __cplusplus >= 201103L
        void
        push_back(value_type&& __x)
        { this->_M_insert(end(), std::move(__x)); }
        
        template<typename... _Args>
        void
        emplace_back(_Args&&... __args)
        { this->_M_insert(end(), std::forward<_Args>(__args)...); }
#endif
```
