https://cp-algorithms.com/data_structures/disjoint_set_union.html

## 什么是并查集（DSU, disjoint set union）
disjoint不相交的，set集合，union合并。所有的集合两两都没有交集，把这样的集合合并起来就是并查集。

## 重要的操作

不想交集合有两个重要操作，找出某个元素所属的集合，以及合并两个集合。所以并查集一般也叫做Union Find。

## 基本元素

从数学上来说，每一个元素本身也是一个独立的集合，DSU中的一种操作就是合并任意两个集合，并查处某个元素所属的集合。
当然，一般来说DSU都会一共第三种操作，就是用一个元素创建一个集合。

## 基本的接口

1. make_set(v) 用一个新元素创建一个接口。
1. union_set(a, b) 合并元素a, b 分别所在的两个集合。
1. find_set(v) 找到v所在的集合，返回集合的leader，这个leader是set中的而一个元数，是作为代表这个集合。

find_set主要用来判断两个元素是否为在同一个集合内。

## 复杂度要求

以上三种操作，数据结构能提供平均为O(1)的时间复杂度。

## 集合的表示

用tree来表述一个集合。
