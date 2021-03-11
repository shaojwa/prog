#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int NMAX = 200000;
char pipe[2][NMAX + 2];
char d[2];

int main(void) {
  int q;
  int n;
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &n);
    scanf("%s%s", pipe[0] + 1, pipe[1] + 1);
    int i = 0, j = 0;
    d[i] = 0;
    for (j = 1; j <= n; ) {
      if (d[i] == 0) {
        if (pipe[i][j] < '3') {
          j++;
          d[i] = 0;
        } else {
          i = 1 - i;
          d[i]= 1;
        } 
      } else {
        if (pipe[i][j] < '3') {
          break;
        } else {
          j++;
          d[i] = 0;
        }
      }
    }

    if (j == n + 1 && i == 1) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
