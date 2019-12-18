#### test_bit
```
arch/arc/include/asm/bitops.h

static __inline__ int
test_bit (int nr, const volatile void *addr)
{
        return 1 & (((const volatile __u32 *) addr)[nr >> 5] >> (nr & 31));
}
```
判断 *addr对应的32位整数从又往左的第nr个比特（从0开始）是否为1。
