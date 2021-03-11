#include <iostream>
#include <set>
#include <list>
using namespace std;

int main(void) {
  int n, k, id, t;
  cin >> n >> k;
  set<int> s;
  list<int> l;
  while (n--) {
    cin >> id;
    if (s.count(id) == 0) {
      if (l.size() == k) {
        t = l.back();
        l.pop_back();
        s.erase(t);
      } 
      s.insert(id);
      l.push_front(id);
    }
  }
  cout << l.size();
  for (int it : l) {
    cout << " " << it ;
  }
}  
