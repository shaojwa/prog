#### issue
```
(gdb) break DMTest::WriteObj
Function "DMTest::WriteObj" not defined.
```
WriteObj is a template function:
```
template<typename T>
int32 WriteObj(dm_data_oper_t &data_oper, const T &data, uint64 &wlen)
{
  bufferlist bl;
  cout << " encode data: " << data << endl;
  ::encode(data, bl);
  co::co_sem sm;
  wlen = bl.length();
  data_oper.length = wlen;
  return _instance->dm.dm_write_obj_data(data_oper, bl, sm);
}
```

#### solution
we should spectied the type when setting template-function breakpoint like:
```
break WriteObj<string>
```
WriteObj is not the name of the template-function, or we can use rbreak:
```
rbreak DMTest::WriteObj*
```
