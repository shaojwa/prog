#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int NMAX = 200000;
int perm[NMAX];
int flag[NMAX];
long long result[NMAX];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &perm[i]);
  }
  for (int i = 0; i < m - 1; i++) { 
    result[0] += abs(perm[i] - perm[i+1]);
  }
  for (int i = 1; i < n; i++) {
    result[i] = result[0];
  }
  int max, min;
  for (int i = 0; i < m - 1; i++) {
    max = perm[i] > perm[i+1] ? perm[i]: perm[i+1];
    min = perm[i] < perm[i+1] ? perm[i]: perm[i+1];
    if (max != min) {
      result[max - 1] += 2 * min - max;
      if (max > min + 1) {
        flag[min]++;
        flag[max - 1]--;
      }
      result[min - 1] += min - 1;
    }
  }
  int delta = 0;
  for (int i = 1; i < n - 1; i++) {
    delta += flag[i];
    result[i] -= delta;
  }
  printf("%lld", result[0]);
  for (int i = 1; i < n; i ++) {
    printf(" %lld", result[i]);
  }
  printf("\n");
  return 0;
}
