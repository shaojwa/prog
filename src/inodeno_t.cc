#include <cstring>
#include <string>
#include <list>
#include <map>
#include <iostream>

using namespace std;


typedef int _inodeno_t;
struct inodeno_t {
  _inodeno_t val;
  inodeno_t():val(0) {
    cout << "inodeno_t()" << endl;
  }

  inodeno_t(_inodeno_t v): val(v) {
    cout << "inodeno_t(int v)" << endl;
  }

  inodeno_t & operator=(_inodeno_t v) {
    val = v;
    cout << "operator=(int v)" << endl;
  }

  operator _inodeno_t() const {
    return val;
  }
};


int main(int argc, char* argv[]) {
  inodeno_t ino = 1102;
  ino = 1203;
  if (ino != 0) {
    cout << "ino != 0: ino.val" << endl;
  }
  return 0;
}
