```
#include <stdio.h>
#include <stdint.h>
int main() {
  uint16_t check = 0x8123u;
  printf("%d\n", ((check & 0xffff) << 16));
  printf("%lx\n", (uint64_t)((check & 0xffff) << 16));
  printf("%u\n", (check & 0xffffu) << 16);
  printf("%lx\n", (uint64_t)((check & 0xffffu) << 16));
  return 0;
}
```
out:
```
-2128412672
ffffffff81230000
2166554624
81230000
```
