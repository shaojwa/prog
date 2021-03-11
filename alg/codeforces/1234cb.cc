#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int NMAX = 200000;
char pipe[2][NMAX + 2];
char nxt[2][NMAX + 2][3];

int main(void) {
  int q;
  int n;
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &n);
    scanf("%s%s", pipe[0] + 1, pipe[1] + 1);
    memset(nxt, 0, sizeof(nxt));
    nxt[0][0][1] = 1;
    for (int i = 1; i <= n; i++) {
      if (nxt[0][i - 1][1]) {
        if (pipe[0][i] <= '2') {
          nxt[0][i][1] = 1;
        } else {
          nxt[0][i][2] = 1;
        }           
      }

      if (nxt[1][i - 1][1]) {
        if (pipe[1][i] <= '2') {
          nxt[1][i][1] = 1;
        } else {
          nxt[1][i][0] = 1;
        }
      }

      if (nxt[0][i][2]) {
        if (pipe[1][i] >= '3') {
          nxt[1][i][1] = 1;
        }
      }

      if (nxt[1][i][0]) {
        if (pipe[0][i] >= '3') {
          nxt[0][i][1] = 1;
        }
      }
    }
    if (nxt[1][n][1]) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  cerr << "\nTime elapsed:" << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
