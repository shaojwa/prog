```
#include <stdio.h>
int main() {
    short a = 1;
    short b = 1;
    printf("sizeof(short) is %lu\n", sizeof(a));
    printf("sizeof(shift) is %lu\n", sizeof(a << 1));
    printf("sizeof(shift) is %lu\n", sizeof(a << b));
    return 0;
}
```
output:
```
sizeof(short) is 2
sizeof(shift) is 4
sizeof(shift) is 4
```
