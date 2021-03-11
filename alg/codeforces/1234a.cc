#include <iostream>
using namespace std;

int main(void) {
  int q, n, a, sum, i;
  cin >> q;
  while (q--) {
    cin >> n;
    sum = 0;
    i = n;
    while (i--) {
      cin >> a;
      sum += a;
    }
    cout << (sum + n - 1) / n << endl;
  }
}
