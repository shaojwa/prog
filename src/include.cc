

#include <iostream>

class Base;
class Derive {
    Base b;
    int fun() {
        return b.x;
    }
};

class Base {
    int x;
    int y;
};

int main() {
    Derive d;
    return 0;
}

