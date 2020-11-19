#include <iostream>
#include <list>

using namespace std;

int main()
{
  list<int> l;
  l.push_back(1);
  l.push_back(5);
  l.push_back(9);
  list<int>::iterator it = l.begin();
  for (int i = 0; i < 10; i++) {
    if (it == l.end()) {
      cout << "it == l.end()" << endl;
    } else {
      cout << *it << endl;
    }
    ++it;
  }
  cout << "----" << endl; 
  it = l.begin();
  while (it != l.end()) {
    cout << *it << endl;
    it = std::next(it);
  }
  return 0;
}
