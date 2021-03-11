## stringstream

stringstream	basic_stringstream<char>
  
## 输出stingstream
直接输出会打印对象的地址，这是以为内cout 对应的basic_ostream有这个重载运算：
```
basic_ostream& operator<<( const void* value );
```
而因为 basic_stringstream 继承自basic_oistream，然后继承basic_ios，最终会有：
```
operator void*() const;
```

## 证实
```
cout << ss << endl;
48 8d 85 80 fe ff ff    lea    -0x180(%rbp),%rax
48 83 c0 68     add    $0x68,%rax
48 89 c7        mov    %rax,%rdi
e8 ca fd ff ff  callq  0x400920 <_ZNKSt9basic_iosIcSt11char_traitsIcEEcvPvEv@plt>
48 89 c6        mov    %rax,%rsi
bf a0 20 60 00  mov    $0x6020a0,%edi
e8 1d fe ff ff  callq  0x400980 <_ZNSolsEPKv@plt>
be b0 09 40 00  mov    $0x4009b0,%esi
48 89 c7        mov    %rax,%rdi
e8 30 fe ff ff  callq  0x4009a0 <_ZNSolsEPFRSoS_E@plt>


//
$ echo "_ZNKSt9basic_iosIcSt11char_traitsIcEEcvPvEv@plt" | c++filt
std::basic_ios<char, std::char_traits<char> >::operator void*() const@plt
```
