直接用it.end(), 这个和一般的it != bl.end() 不太一样，因为iterator这个类中本身实现了end方法。
```
/// true if iterator is at the end of the buffer::list
bool end() const {
	return p == ls->end();
}
```
