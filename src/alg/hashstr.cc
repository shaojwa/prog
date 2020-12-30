#include <iostream>
using namespace std;


int hash0(const string &str)
{
  int hash = 0;
  int len  = str.length();
  if (len)
  {
    char a, b, c, d;
    a = str[(len<4) ? 0 : (len-4)];
    b = str[(len<3) ? 0 : (len-3)];
    c = str[(len<2) ? 0 : (len-2)];
    d = str[len - 1];
    // a has less significant than b, same with c and d
    hash = (((a & 0xf) << 12) | ((b & 0xf) << 8) | ((c & 0xf) << 4) | (d & 0xf));
  }
  return hash;
}

int hash1(const string &str)
{
  unsigned hash = 0;
  const char *pstr = str.data();
  unsigned length = str.length();
  while (length--) {
    unsigned char c = *pstr++;
    hash = (hash + (c << 4) + (c >> 4)) * 11;
  }
  return hash;
}

void test_hash(int times, const string &str) {
  int x = 0;
  unsigned long long time;
  struct timespec start, end;

  clock_gettime(CLOCK_MONOTONIC, &start);
  for (int i = 0; i < times; i++) {
    hash0(str);
  }
  clock_gettime(CLOCK_MONOTONIC, &end);
  time = (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);
  cout << __func__ << " time " << time << " ns, x " << x << endl;

  clock_gettime(CLOCK_MONOTONIC, &start);
  for (int i = 0; i < times; i++) {
    hash1(str);
  }
  clock_gettime(CLOCK_MONOTONIC, &end);
  time = (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);
  cout << __func__ << " time " << time << " ns, x " << x << endl;
}

int main() {
  string str = "benchmark_data_node160_1416072_object390933";
  test_hash(10000, str);
  return 0;
}
