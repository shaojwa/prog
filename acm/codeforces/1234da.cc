#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int NMAX = 100000;
char s[NMAX + 1];
char flag[26];

int main(void) {
  int q, t, p, l, r, count;
  char c;
  scanf("%s", s);
  scanf("%d", &q);
  for (int i = 0; i < q; i++) { 
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d %c", &p, &c);
      s[p - 1] = c;
    } else {
      scanf("%d %d", &l, &r);
      memset(flag, 0, sizeof(flag));
      count = 0;
      for (int j = l; j <= r; j++) {
        int tmp  = s[j - 1] -  'a';
        if (flag[tmp] == 0) {
          flag[tmp] = 1;
          count++;
          if (count == 26) {
            break;
          }           
        }
      }
      printf("%d\n", count);
    }
  }  
  return 0;
}
