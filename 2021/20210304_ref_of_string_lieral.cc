#include <iostream>
using namespace std;

int main() {
  auto ref = &("hello defg");
  const char *pc = "hello defg";
  cout << " rreeff " << ref << endl;
  cout << " ppcc " << reinterpret_cast<const void*>(pc) << endl;
  cout << " new ref " << ref << endl;
  return 0;
}
