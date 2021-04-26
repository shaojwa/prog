1. https://stackoverflow.com/questions/20769930/what-is-the-difference-between-kmemleak-and-kmemcheck-and-how-to-enable-these-t
2. https://www.kernel.org/doc/html/v4.14/dev-tools/kmemcheck.html
3. https://www.kernel.org/doc/Documentation/kmemcheck.txt
4. https://www.kernel.org/doc/Documentation/kmemleak.txt

## 什么是踩内存
我的理解是，踩内存，不是内存非法访问，而是访问了本不应该自己访问的数据，操作本身是合法的，只是不正确，踩内存常常是内存非法访问的起因。

## 什么是内存非法访问
因为访问未初始化的内存，导致进一步访问非法地址。

## kmemcheck

## kmemleak
