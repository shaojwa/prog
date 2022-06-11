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
    void play() {
      cout << __func__ << endl;
    }
};


int  crosses_init(bool goto_over_init, bool return_before_init) {
  if (goto_over_init) {
    goto processing;
  } 
  if (return_before_init) {
    return -1;
  }
 
processing:
  Dog dog; // init
  dog.play();
  goto end;
 
end:
  return 0;
}

int main() {
  crosses_init(true, true);
  crosses_init(false, false);
  return 0;
}
