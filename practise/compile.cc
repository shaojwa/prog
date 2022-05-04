
#include "compile.h"
#include <iostream>
#include <cstddef>
using namespace std;

int reorder1(int a, int b) {
    int *c = &a;
    int *d = c;
    return a + *d;
}

int ga, gb;
void reorder2() {
    ga = gb + 1;
    gb = 0;
}

