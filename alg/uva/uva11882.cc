#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
 
const int SIZE = 16;
const int LEN = 32;
char map[SIZE][SIZE];
char dfsm[SIZE][SIZE];
char bfsm[SIZE][SIZE];
char num[LEN];
char ans[LEN];
int  ans_len;
int cnt = 0;
int r, c;
 
int bfsq[LEN][2];
char part[LEN];
int dict[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
 
int bfs(int x, int y) {
  int tx, ty;
  int pos = 0, cur = 0;
  memset(bfsm, 0, sizeof(bfsm));
  while (true) {
    for (int i = 0; i < 4; i++) {
      tx = x + dict[i][0];
      ty = y + dict[i][1];
      if (tx >= 0 && tx < r && ty >=0  && ty < c && map[tx][ty] != '#'
          && dfsm[tx][ty] == 0 && bfsm[tx][ty] == 0) {
        part[pos] = map[tx][ty];
        bfsq[pos][0] = tx;
        bfsq[pos][1] = ty;
        bfsm[tx][ty] = 1;
        pos++;
      }
    }
    if (cur == pos) {
      break;
    }
    x = bfsq[cur][0];
    y = bfsq[cur][1];
    cur++;
  }
  part[pos] = 0;
  return pos; 
}
 
 
void dfs(int x, int y) {
  num[cnt++] = map[x][y];
  bool end = true;
  if (cnt < ans_len) {
    int bfs_len = bfs(x, y);
    if (cnt + bfs_len < ans_len) {
      goto out;
    } else if (cnt + bfs_len == ans_len) {
      if (strncmp(num, ans, cnt) < 0) {
        goto out;
      }
    } 
  }
  if (x > 0 && map[x - 1][y] != '#' && dfsm[x - 1][y] == 0) {
    dfsm[x - 1][y] = 1;
    dfs(x - 1, y);
    dfsm[x - 1][y] = 0;
    end = false;
  } 
  if (x < r - 1  && map[x + 1][y] != '#' && dfsm[x + 1][y] == 0) {
    dfsm[x + 1][y] = 1;
    dfs(x + 1, y);
    dfsm[x + 1][y] = 0;
    end = false;
  } 
  if (y < c - 1  && map[x][y + 1] != '#' && dfsm[x][y + 1] == 0) {
    dfsm[x][y + 1] = 1;
    dfs(x, y + 1);
    dfsm[x][y + 1] = 0;
    end = false;
  } 
  if (y > 0 && map[x][y - 1] != '#' && dfsm[x][y - 1] == 0) {
    dfsm[x][y - 1] = 1;
    dfs(x, y - 1);
    dfsm[x][y - 1] = 0;
    end = false;
  }
 
  if (end) {
    num[cnt] = 0;
    if (cnt > ans_len) {
      strcpy(ans, num);
      ans_len = cnt;
    } else if (cnt == ans_len && strcmp(num, ans) > 0) {
      strcpy(ans, num);
    }
  }
out:
  cnt--;
}
 
 
int main(void) {
  while (cin >> r >> c && c && r) {
    int i = 0;
    while (i != r) {
      cin >> map[i++];
    }
    cnt = 0;
    ans_len = 0;
    for(int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {                
        if (map[i][j] != '#') {
          dfsm[i][j] = 1;
          dfs(i, j);  
          dfsm[i][j] = 0;
        }               
      }
    }
    cout << ans << endl;
  }
  return 0;
}
