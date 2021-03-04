//
// -O0 -fno-elide-constructors
// 
class A {
   public:
    A() { puts("construct"); }
    A(const A &a) { puts("copy"); }
};

A func() {
    A a;
    return a;
}

int main() {
    A a = func();
    return 0;
}
