// testing  string += int
// it will convert int to char to append

#include <iostream>
using namespace std;

int main() {
  string str = "";
  str += "test";
  str += 32;
  cout << "str=[" << str << "]" << endl;
  return 0;
}
