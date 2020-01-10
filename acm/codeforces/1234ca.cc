#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int NMAX = 200000;
char pipe[2][NMAX + 2];
char reach[2][NMAX];
char nxt[2][NMAX][3];

int main(void) {
  int q;
  int n;
  cin >> q;
  // reach[0][0] = 1;
  while (q--) {
    cin >> n;
    cin >> pipe[0] + 1 >> pipe[1] + 1;    
    // cout << pipe[0] + 1 << endl;
    // cout << pipe[1] + 1 << endl;    
    memset(nxt, 0, sizeof(nxt));
    nxt[0][0][1] = 1;
    // memset(reach, 0, sizeof(reach));
    for (int i = 1; i <= n; i++) {
      
      // reach [0][i]
      if (nxt[0][i - 1][1]) {
        // reach[0][i] = 1;
        if (pipe[0][i] <= '2') {
          //cout << "[0][" << i << "][1]" << endl;
          nxt[0][i][1] = 1;
        } else {
          //cout << "[0][" << i << "][2]" << endl;
          nxt[0][i][2] = 1;
        }           
      }

      // reach [1][i]
      if (nxt[1][i - 1][1]) {
        // reach[1][i] = 1;
        if (pipe[1][i] <= '2') {
          //cout << "[1][" << i << "][1]" << endl;
          nxt[1][i][1] = 1;
        } else {
          //cout << "[1][" << i << "][0]" << endl;
          nxt[1][i][0] = 1;
        }
      }

      if (nxt[0][i][2]) {
        // reach[1][i] = 1;
        if (pipe[1][i] >= '3') {
          //cout << "[1][" << i << "][1]" << endl;
          nxt[1][i][1] = 1;
        }
      }

      if (nxt[1][i][0]) {
        // reach [0][i] = 1;
        if (pipe[0][i] >= '3') {
          //cout << "[0][" << i << "][1]" << endl;
          nxt[0][i][1] = 1;
        }
      }
    }
    if (nxt[1][n][1]) {
      cout << "YES" << endl;
    } else {
      cout << "NO"  << endl;
    }
  }
  return 0;
}
