/*
* std 中 set是用红黑树实现的，元素的插入会先找到插入的位置，然后通过拷贝构造函数构造出来。
*/

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
  cout << "---- begin insert ----" << endl;
  cls_set.insert(c);
  cout << "--------" << endl;
  cls_set.insert(d);
  cout << "--------" << endl;
  cls_set.insert(e);
  cout << "---- end insert----" << endl;
}

int main(void) {
  test_func();
  return 0;
}

/*  output
Cls(n_)
Cls(n_)
Cls(n_)
---- begin insert ----
Cls(Cls &c) c.n = 1
--------
operator<(const Cls &c)
operator<(const Cls &c)
operator<(const Cls &c)
Cls(Cls &c) c.n = 2
--------
operator<(const Cls &c)
operator<(const Cls &c)
operator<(const Cls &c)
operator<(const Cls &c)
Cls(Cls &c) c.n = 3
---- end insert----
*/
