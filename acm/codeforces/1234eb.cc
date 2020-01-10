#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef unsigned int u32;
typedef int s32;

const u32 NMAX = 200000;
s32 perm[NMAX];
u32 result[NMAX];

int main(void) {
  u32 n, m;
  scanf("%u %u", &n, &m);
  for (u32 i = 0; i < m; i++) {
    scanf("%u", &perm[i]);
  }
  for (u32 i = 0; i < m - 1; i++) { 
    result[0] += abs(perm[i] - perm[i+1]);
  }
  for (u32 i = 1; i < m; i++) {
    result[i] = result[0];
  }
  u32 max, min;
  for (u32 i = 0; i < n - 1; i++) {
    max = perm[i] > perm[i+1] ? perm[i]: perm[i+1];
    min = perm[i] < perm[i+1] ? perm[i]: perm[i+1];
    if (max != min) {
      result[max - 1] += 2 * min - max;
      for (u32 j = min; j < max - 1; j++) {
        result[j] -= 1;
      }
      result[min - 1] += min - 1;
    }
  }
  printf(" %u", result[0]);
  for (u32 i = 1; i < n; i ++) {
    printf(" %u", result[i]);
  }
  printf("\n");
  return 0;
}
