#### crosses initialization
```
#include <iostream>
using namespace std;

class Dog {
  string name;
  int age;
};

int main() {
  int n = 0;

  if (n%2) {
    goto end;
  }
  Dog d;
end:
  return 0;
}
```
