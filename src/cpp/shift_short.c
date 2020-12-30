#include <stdio.h>
int main() {
    short n = 1;
    printf("%lu\n", sizeof(n));
    printf("%lu\n", sizeof(n << 0));
    char c = 1;
    printf("%lu\n", c << 16);
    printf("%lu\n", sizeof(c << 16));
    return 0;
}
