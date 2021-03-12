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
      cout << "Cls(const Cls&c)" << endl;
      n = c.n;
    }
    Cls &operator=(Cls &c) {
      n = c.n;
    }
    bool operator<(const Cls &c) const {
      return n < c.n;
    }
    int n;
};

void test_map() {
  map<int, Cls> mp;
  Cls a, b;
  cout << "&a = " << &a << ", &b = " << &b << endl;
  cout << "---- set map ----" << endl;
  mp[1] = a;
  mp[2] = b;
  cout << "&mp[1]= " << &mp[1] << ", &mp[2] = " << &mp[2]<< endl;
  
  cout << "---- interator  ----" << endl;
  map<int, Cls>::iterator it;
  for (it = mp.begin(); it != mp.end(); ++it) {
    cout << &(it->second) << endl;
  }
  cout << "---- auto no ref  ----" << endl;
  for (auto &m : mp) {
    cout << &(m.second) << endl;
  }
}

int main(void) {
  test_map();
  return 0;
}
