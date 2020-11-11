#include<iostream>
using namespace std;

int count[256];

int main() {
  for (int i = 'a'; i <= 'z'; i++) {
    for (int j = 'a'; j <= 'z'; j++) {
      int t = i + j * 3;
      count[t % 256]++;
    }
  }
  for (int i = 0; i < 256; i++) {
    cout << count[i] << endl;
  }
  return 0;
}
