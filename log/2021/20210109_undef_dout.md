dout的undef似乎不需要带参数：
```
#define DCACHE_GTEST_DM
#ifdef DCACHE_GTEST_DM
#undef dout
#undef derr
#undef dendl
#define dout(v)   cout
#define derr      cout
#define dendl     endl
#endif
```
