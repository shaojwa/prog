### 总体原则

#### 增加

无需容器：只能按值插入，无法指定位置。所以insert接口只有值。
有序容器：插入就需要指定位置和值，比如list中的insert。如果省略位置就变成push。

#### 删除

无序容器：都用earse。（1）迭代器指定位置，以及按值删除。（2）或者按值删除。
有序容器：（1）通过位置删除用earse。（2）通过值删除用remove。

#### 查询

#### list

* list 两头插入用push，中间插入用insert。
* list 两头删除用pop，中间删除用erase。
* list 没有直接修改的接口。
* 没有直接的find接口。

问题：

* 为什么list的pop_back没有返回值？
stackoverflow上的解释是，对象的构造函数可能会抛异常，这样通过pop系列函数返回时，对象已经pop掉，而因为异常可能没有获取到这个对象，那么这个对象就会丢失。容器的pop都无法实现成exception safe。

[参考1](https://stackoverflow.com/questions/12600330/pop-back-return-value)

[参考2](http://www.gotw.ca/gotw/008.htm)

* list 的删除接口为什么用erase，而不用remove？
受限remove这个词已经被用于一个算法名，定义在<algorithm>中。要留意remove的实现原理。remove其实不会真的删除元数，只是将不用删除的元数过滤出来。
类属于属组中把不需要删除的元数往前移，这样移动之后访问到的就都是不需要删除的远处。其实remove算法设计的时候是没有删除元数权限的，只有遍历以及赋值。
但是需要注意的是，list有erase也有remove接口，因为如果要真的删除某个值，只有earse是不够的，因为earse一般都是针对位置的删除（当然set中也有针对值的），所以list中原先针对值的删除需要remove和erase配合，remove返回需要删除的位置，然后erase开始从该位置进行删除，所以list中也有remove接口。
    
所以需要区别对待不同的container中的同名接口其实参数有时候是有区别的。

注意：
* 空list的pop行为是undefined，也就是说不可控，实际情况在linux下是 abort。

#### set

* 插入用insert
* 删除用erase
* 没有直接修改的接口
* 查找用find，count 也可以，都是用的log复杂度，contains是C++20才有的接口。

注意：

* set中按照位置的删除同erase。
* set中没有remove借口，按照元数值的删除已经在erase中体现。

#### bitset

#### std::ios::sync_with_stdio(0);

#### std::cin.tie(0)

#### stdc++

    #include <bits/stdc++.h>

这个头文件包括了所有的cpp标准库以及STL头文件，据说这是为了测试以及教学使用，平时做工程一般不推荐用，因为这会增加可能的不必要的麻烦以及编译时间。

#### 代码头部

    typedef unsigned long long ull;
    typedef long long ll;
    typedef long double ld;

    #define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

    const ll INF = 1e14;
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};

    cerr << "\nTime elapsed:" << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";

#### 头文件顺序

      头文件包含可以按照字典序来避免重复包含比如
      <cstdio>
      <cstdlib>
      <cstring>
      
#### 命名
  
* 大数属组全局定义，其他的都局部定义。
* 常数全大写变量全小写不带下划线。
* 全局变量一般用g开头标记。
* ijk只用做循环变量。
* 函数名只用下划线不用大小写。
* 搜索函数一般直接叫dfs或者bfs。
* 搜索的标记数字一般叫mark，或者dfsm，或者bfsm。
* 状态数组一般叫map和state。
* 变化量一般叫delta。
* 标记数组一般叫flag。
* 偏移用offset。
      
#### 搜索

dfs递归搜索接口返回状态判断代码在函数开始处。

mark数组的标记可以在dfs调用前后，这样如果dfs内部有多处返回时就比较简单，但是dfs内部地递归时也要加上mark属组标记。
如果在dfs函数开头和退出是标记，那么dfs内部的递归调用就不要再次标记，简化代码，但是如果有多处返回，那么返回前的清理比较容易忘记。

#### gcc

      [wsh@centos ~]$ gcc --version
      gcc (GCC) 4.8.5 20150623 (Red Hat 4.8.5-28)
      Copyright (C) 2015 Free Software Foundation, Inc.
      This is free software; see the source for copying conditions.  There is NO
      warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
      
      [root@li984-80 ~]# gcc --version
      gcc (GCC) 4.8.5 20150623 (Red Hat 4.8.5-36)
      Copyright (C) 2015 Free Software Foundation, Inc.
      This is free software; see the source for copying conditions.  There is NO
      warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.


#### uname 
      [wsh@centos ~]$ uname -a
      Linux centos 3.10.0-862.el7.x86_64 #1 SMP Fri Apr 20 16:44:24 UTC 2018 x86_64 x86_64 x86_64 GNU/Linux 
      
      [root@li984-80 ~]# uname -a
      Linux li984-80 3.10.0-957.27.2.el7.x86_64 #1 SMP Mon Jul 29 17:46:05 UTC 2019 x86_64 x86_64 x86_64 GNU/Linux
      

#### cf

cf 中换行和行尾的空格要求不严，对于输出只有数值的题目，只要数值的个数以及值和答案相等就可以。

#### far的使用

    http://codeforces.com/blog/entry/532
    https://www.quora.com/Which-editor-IDE-does-tourist-Gennady-Korotkevich-use-for-programming-competitions
