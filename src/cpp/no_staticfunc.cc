#include <iostream>
using namespace std;

class A
{
  int x;
  static int s;
public:
  A(int a):x(a){}
  void add(int y) {
    x += y;
  }
  static void sum(int y) {
  }
};

class B
{
  int x;
  static int s;
public:
  B(){}
  void add(int y);
  static void sum(int y);
};

void B::add(int y) {
  cout << "B::add()" << endl;
}
void B::sum(int y) {
  s-= y;
}
int B::s = 0;

int main() {
  return 0;
}
