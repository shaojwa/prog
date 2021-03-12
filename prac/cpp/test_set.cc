#include <map>
#include <set>
#include <iostream>

using namespace std;
class Cls {
public:
    Cls(int n_ = 0): n(n_) {
      cout << "Cls(n_)" << endl;
    }
    Cls(const Cls &c) {
      cout << "Cls(Cls &c) c.n = " << c.n << endl;
      n = c.n;
    }
    void operator=(const Cls &c) {
      cout << "operator=(const Cls &c)" << endl;
      n = c.n;
    }
    bool operator<(const Cls &c) const {
      cout << "operator<(const Cls &c)" << endl;
      return n < c.n;
    }
    int n;
};

void test_func() {
  set<Cls> cls_set;
  Cls c(1), d(2), e(3);
  cls_set.insert(c);
  cls_set.insert(d);
  cls_set.insert(e);
  cout << "--------" << endl;
  for (auto &c : cls_set) {
    cout << "c.n = " << c.n << ", &c = " << &c << endl;
  }
}

int main(void) {
  test_func();
  return 0;
}
