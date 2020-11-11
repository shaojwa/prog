#include <string>
#include <iostream>

using namespace std;

int main(void) {
  size_t pos;
  string str("wang");
  pos = str.find("=");
  cout << "string::npos: " << string::npos << endl;
  cout << "pos: " << pos << ", str size: " << str.size() << endl;
  pos = str.find("g");
  cout << "pos: " << pos << ", str size: " << str.size() << endl;
  return 0;
}
