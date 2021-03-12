#include <iostream>
#include <string>

using namespace std;

int main() {
  string cmds[] = {
    "stat-hash",
    "stat-hash",
    "stat-hash",
    "stat-hash",
    "stat-hash"
  };

  cout << "sizeof(cmds) " << sizeof(cmds) << endl;
  string str = "stat-hash";
  cout << "sizeof(str) " <<  sizeof(str) << endl;
  return 0;
}
