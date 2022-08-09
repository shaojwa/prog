#include <iostream>
using namespace std;

int main() {
  char *symbol = (char*)"hello world";
  string symstr = string(symbol, 10);
  cout << symstr << endl;
  return 0;
}
