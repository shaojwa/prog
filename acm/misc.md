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
