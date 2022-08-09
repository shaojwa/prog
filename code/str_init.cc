#include <iostream>
using namespace std;

int main() {
  char *symbol = nullptr;
  string symstr(symbol, 0);
  symstr = "hello" + symstr + "world";
  cout << symstr << endl;
  return 0;
}
