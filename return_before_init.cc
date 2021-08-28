#include <iostream>
using namespace std;


class Dog {
  public:
    Dog() {
      cout << __func__ << endl;
    }
    ~Dog() {
      cout << __func__ << endl;
    }
};


int  test(bool return_before_init) {
  if (return_before_init) {
    return -1;
  }
  Dog dog;
  return 0;
}

int main() {
  test(true);
  test(false);
  return 0;
}
