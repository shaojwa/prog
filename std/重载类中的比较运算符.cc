/*
* 如果类作为std::set等元素的中的元素，那儿需要在类中重载比较运算符，重载的时候，operator< 必须是const修饰。
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
    Cls &operator=(Cls &c) {
      n = c.n;
    }
    bool operator<(const Cls &c) const {
      cout << "operator<" << endl;
      return n < c.n;
    }
    int n;
};

void test_func() {
  set<Cls> cls_set;
  Cls c(1), d(2);
  cls_set.insert(c);
  cls_set.insert(d);
}

int main(void) {
  test_func();
  return 0;
}

/* output
Cls(n_)
Cls(n_)
operator<
operator<
operator<
*/
