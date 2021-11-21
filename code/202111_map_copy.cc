#include <atomic>
#include <map>
#include <iostream>
using namespace std;

struct req_hit_t {
  uint32_t req_len;
  uint32_t hit_len;
};

struct stat_t {
  std::atomic<uint32_t> stat[8];
  map<uint32_t, req_hit_t>  hits;
};

int main()
{
  int i = 0;
  stat_t a, b;
  a.hits[0]= {8, 8};
  b.hits = a.hits;
  cout << "a.hits[" << i << "] " << a.hits[i].req_len << endl;
  cout << "b.hits[" << i << "] " << b.hits[i].req_len << endl;
  a.hits[0].req_len = 16;
  cout << "a.hits[" << i << "] " << a.hits[i].req_len << endl;
  cout << "b.hits[" << i << "] " << b.hits[i].req_len << endl;
  return 0;
}

