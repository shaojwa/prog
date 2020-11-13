#include <iostream>
#include <list>

using namespace std;


struct interval_t {
    interval_t(): offset(0), len(0) {}
    interval_t(uint64_t offset_, uint64_t len_): offset(offset_), len(len_) {}
    uint64_t offset;
    uint64_t len;
    bool operator < (const interval_t &other) const {
        if (offset < other.offset) {
            return true;
        }
        return false;
    }
};


int main()
{
  list<interval_t> data;
  data.push_back(interval_t(0, 100));
  data.push_back(interval_t(200, 100));
  data.push_back(interval_t(160, 20));
  data.push_back(interval_t(100, 50));
  data.sort();
  list<interval_t>::iterator cur = data.begin();
  list<interval_t>::iterator nxt =  std::next(cur);
  while (nxt != data.end()) {
    if (cur->offset + cur->len == nxt->offset) {
        cur->len += nxt->len;
        data.erase(nxt);
    } else {
        ++cur;
    }
    nxt = std::next(cur);
  }
  for(auto &it:data) {
    cout << "["  << it.offset << ", " << it.len << "]" << endl;
  }
  return 0;
}
