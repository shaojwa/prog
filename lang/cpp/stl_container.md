## initialization
#### vector initilization
```
vector<string> cmd = {"show-hash-stat"};
// identical to
vector<string> cmd({"show-hash-stat"});
```

#### map initilization
```
map<uint64, uint64> map_want = {{offset, length}};
// identical to
map<uint64, uint64> map_want({{offset, length}});
```

## stl 容器插入原则
1. 容器都有insert系列接口。
1. 线性容器：插入后保序，有push_back系列接口， insert必须指定位置。
1. 集合容器：插入不保序，没有push_back系列接口，insert不需要指定位置。

## stl 容器删除原则
* 都有erase接口，都支持值删除和迭代器删除。
* 线性容器：（1）指定值删除（2）迭代器删除，需要指定位置。
* 集合容器：（1）指定值删除（2）迭代器删除。

#### questions
* list 的删除接口为什么用erase，而不用remove？
受限remove这个词已经被用于一个算法名，定义在<algorithm>中。要留意remove的实现原理。remove其实不会真的删除元数，只是将不用删除的元数过滤出来。
类属于属组中把不需要删除的元数往前移，这样移动之后访问到的就都是不需要删除的远处。其实remove算法设计的时候是没有删除元数权限的，只有遍历以及赋值。
但是需要注意的是，list有erase也有remove接口，因为如果要真的删除某个值，只有earse是不够的，因为earse一般都是针对位置的删除（当然set中也有针对值的），所以list中原先针对值的删除需要remove和erase配合，remove返回需要删除的位置，然后erase开始从该位置进行删除，所以list中也有remove接口。
    
## stl 容器修改
1. set没有直接的修改接口，也没必要，因为没有key。其实list严格来说也没有修改接口，只有查找接口。

## stl 容器查询原则
1. 线性容器只能遍历查找，没有find接口。
1. 集合容器可以用find返回迭代器，count返回数量。

#### questions
**why no contains member-function in containers like set?**
set 中的contains是C++20才有的接口。

## string
string放在list后面是因为string和list最像。
* 中的substr接口用来获取子串
* string中的find接口如果找到的字串在开头那么会返回0
所以不能通过 if (str.find("pattern"))来判断能找到，而要通过 if (string::npos != str.find("pattern")) 来进行。

## 容器使用的注意点
1. list 两头插入用push，中间插入用insert，两头删除用pop，中间删除用erase，没有直接的find接口。
1. 空list的pop行为是undefined，也就是说不可控，实际情况在linux下是 abort。
1. map中判断一个key是否存在用count函数.

## questions

* 为什么list的pop_back没有返回值？
stackoverflow上的解释是，对象的构造函数可能会抛异常，这样通过pop系列函数返回时，对象已经pop掉，而因为异常可能没有获取到这个对象，那么这个对象就会丢失。容器的pop都无法实现成exception safe。

所以需要区别对待不同的container中的同名接口其实参数有时候是有区别的。

#### boost中的侵入式指针

typedef boost::intrusive_ptr<Inode> InodeRef 的 get()
```  
void intrusive_ptr_add_ref(Inode *in) {
  in->get();
}
```
什么时候会调用intrusive_ptr_add_ref(), intrusive_ptr递增一个非空指针上的引用计数时。
    
#### 参考

```
https://stackoverflow.com/questions/12600330/pop-back-return-value
http://www.gotw.ca/gotw/008.htm
```
