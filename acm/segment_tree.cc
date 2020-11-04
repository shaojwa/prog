#include <iostream>
using namespace std;

const uint32_t NMAX = 1000;
int a[NMAX], t[4 * NMAX];
uint32_t n;

void build(int32_t a[], uint32_t tl, uint32_t tr, int32_t t[], uint32_t v) {
  if (tl == tr) {
    t[v] = a[tl];
    return;
  }
  uint32_t m = (tl + tr ) / 2;
  build(a, tl, m, t, 2 * v + 1);
  build(a, m + 1, tr, t, 2 * v + 2);
  t[v] = t[2 * v + 1] + t[2 * v + 2];
}

int32_t query(int32_t t[], uint32_t v, uint32_t tl, uint32_t tr, uint32_t l, uint32_t r) {
  // cout << v << ", " << tl << ", " << tr << ", " << l << ", " << r << endl;
  if (tl == l && tr == r) {
    return t[v];
  }
  uint32_t m = (tl + tr) / 2;
  if (l > m) {
    return query(t, 2 * v + 2, m + 1, tr, l, r);
  } else if (r <= m) {
    return query(t, 2 * v + 1, tl, m, l, r);
  } else {
    return query(t, 2 * v + 1, tl , m, l, m) + query(t, 2 * v + 2, m + 1, tr, m + 1, r);
  }
}

uint32_t from, to;

int main() {
  cout << "input n: " << endl;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  } 
  build(a, 0, n - 1, t, 0);
  //for (int i = 0; i < 4 * n; i++) {
  //  cout << "[" << i << "]" << t[i] << " ";
  //}
  while (true) {
    cout << "input from and to: "; 
    cin >> from >> to;
    if (from == 0 && to == 0) {
      break;
    }
    cout << "sum of " << from << "-" << to << " is:" << query(t, 0, 0, n - 1, from, to) << endl;
  }
  return 0;
}
