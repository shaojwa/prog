#include <map>
#include <iostream>

using namespace std;

void test_multimap() {
  multimap<int, int> test;
  test.insert(std::make_pair<int,int>(1,1));
  test.insert(std::make_pair<int,int>(2,22));
  test.insert(std::make_pair<int,int>(2,222));
  test.insert(std::make_pair<int,int>(2,2222));
  
  multimap<int,int>::iterator it;
  while(true) {
    it = test.find(2);
    if (it == test.end()) {
      break;
    }
    cout << it->second << endl;
    test.erase(it);
  }
}

int main(void) {
  test_multimap();
  return 0;
}
