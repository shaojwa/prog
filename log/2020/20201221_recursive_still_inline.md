```
#include <iostream>
using namespace std;

class B
{
  int x;
  static int s;
public:
  B(){}
  inline void add(int y);
  static void sum(int y);
};

void B::add(int y) {
  cout << "B::add()" << endl;
  add(0);
}
void B::sum(int y) {
  s-= y;
}
int B::s = 0;

int main() {
  B b;
  return 0;
}
```
