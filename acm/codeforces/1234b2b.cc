#include <iostream>
#include <bitset>
#include <list>
using namespace std;

bitset<1000000001> bs;
int main(void) {
  int n, k, id, t;
  cin >> n >> k;
  list<int> l;
  while (n--) {
    cin >> id;
    if (bs[id] == 0) {
      if (l.size() == k) {
        t = l.back();
        l.pop_back();
        bs[t] = 0;
      } 
      bs[id] = 1;
      l.push_front(id);
    }
  }
  cout << l.size();
  for (int it : l) {
    cout << " " << it ;
  }
}  
