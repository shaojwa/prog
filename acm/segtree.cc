#include <iostream>
using namespace std;

const int NMAX = 1000;
int a[NMAX], t[4 * NMAX];
int n;

void build(int a[], int tl, int tr, int t[], int v) {
  if (tl == tr) {
    t[v] = a[tl];
    return;
  }
  int m = (tl + tr ) / 2;
  build(a, tl, m, t, 2 * v + 1);
  build(a, m + 1, tr, t, 2 * v + 2);
  t[v] = t[2 * v + 1] + t[2 * v + 2];
}

int query(int t[], int v, int tl, int tr, int l, int r) {
  // cout << v << ", " << tl << ", " << tr << ", " << l << ", " << r << endl;
  if (tl == l && tr == r) {
    return t[v];
  }
  int m = (tl + tr) / 2;
  if (l > m) {
    return query(t, 2 * v + 2, m + 1, tr, l, r);
  } else if (r <= m) {
    return query(t, 2 * v + 1, tl, m, l, r);
  } else {
    return (query(t, 2 * v + 1, tl , m, l, m) +
      query(t, 2 * v + 2, m + 1, tr, m + 1, r));
  }
}


// return the index of the range
int find_kth(int v, int tl, int tr, int k) {
  if (st[v] < k) {
    return -1;
  }
  if (tl == tr) {
    return tl;
  }
  int tm = (tl + tr)/2;
  if (k > st[v*2]) {
    find_kth(v*2+1, tm+1, tr , k - st[v*2]);
  } else {
    find_kth(v*2, tl, tm, k);
  }
}

int main() {
  int from, to;

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
    cout << "sum of " << from << "-" << to << " is:"
      << query(t, 0, 0, n - 1, from, to) << endl;
  }
  return 0;
}
