#include <iostream>

using namespace std;

struct snapid_t {
  int val;
  snapid_t(int v=0) : val(v) {
    cout << "snapid_t(int) " << endl;
  }
  snapid_t& operator=(const snapid_t & snap) {
    val = snap.val;
    cout << "operator=(const snapid_t &snap)" << endl;
  }
  snapid_t operator+=(snapid_t o) {
    val += o.val; return *this; 
  }
  snapid_t operator++() {
    ++val; return *this; 
  }
  operator int() const {
    return val;
  }
};

int main () {
  snapid_t snap;
  snap = 1;
  return 0;
}
