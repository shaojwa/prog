#### stringstream

stringstream	basic_stringstream<char>
  
#### 直接输出
直接输出会打印对象的地址，这是以为内cout 对应的basic_ostream有这个重载运算：
```
basic_ostream& operator<<( const void* value );
```
而因为 basic_stringstream 继承自basic_oistream，然后继承basic_ios，最终会有：
```
operator void*() const;
```
