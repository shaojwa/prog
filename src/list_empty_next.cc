#include <iostream>
#include <list>

using namespace std;

int main()
{
  list<int> l;
  list<int>::iterator it = l.begin();
  if (it == l.end()) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
  ++it;
  if (it == l.end()) {
    cout << "yes" << endl;
  } else {
    cout << " no " << endl;
  }
  return 0;
}
