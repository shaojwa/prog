
// using code-block to suppress the compile-error of crosses-initialization
// 20201216

#include <iostream>
using namespace std;

class Dog {
  string name;
  int age;
  public:
  int get_age() {
    return age;
  }
};

int main() {
  int n = 0;

  if (n%2) {
    goto end;
  }
  {
    Dog d;
    cout << d.get_age() << endl;
  }
end:
  return 0;
}
