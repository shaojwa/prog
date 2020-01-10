#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

typedef unsigned int u32;
typedef int s32;

const u32 NMAX = 200000;
s32 perm[NMAX];

int main(void) {
  u32 n, m;
  scanf("%u %u", &n, &m);
  for (u32 i = 0; i < m; i ++) {
    scanf("%u", &perm[i]);
  }
  u32 sum = 0;
  s32 p1, p2;
  for (u32 i = 1; i <= n; i++) {
    sum = 0;
    p1 = perm[0];
    if (p1 < i) p1++;
    else if (p1 == i) p1 = 1;
    for (u32 j = 1; j < m; j++) {
      p2 = perm[j];
      if (p2 < i) p2++; 
      else if (p2 == i) p2 = 1;
      sum += abs(p1 - p2);
      p1 = p2;
    }
    printf(" %u", sum);
  }
  printf("\n", sum);
  return 0;
}
