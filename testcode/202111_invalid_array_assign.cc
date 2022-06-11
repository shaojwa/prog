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
  stat_t a, b;
  a.stat = b.stat;
  return 0;
}

