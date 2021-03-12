

// we comfirm that: the compiler parses the source file from top to buttom
// so the compiler can NOT see the defination of ClassB when parsing ClassA.

class ClassB;
class ClassA {
  ClassB b;
};

class ClassB {
  ClassA* ap;
};


int main() {
  ClassA a;
  return 0;
}
