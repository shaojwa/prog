#include <iostream>
using namespace std;

void swap(int *left, int *right) {
  int tmp = *left;
  *left = *right;
  *right = tmp;
}

// insert sort
void isort2 (int *base, size_t nmemb) {
  int i = 0, j = 0;
  for (i = 0; i < nmemb - 1; i++) {
    for (j = i + 1; j < nmemb; j++) {
      if (base[i] > base[j]){
        swap(base + i, base + j);
      }
    }
  }
}


static constexpr int BUF_SIZE = 10000;

int num[BUF_SIZE];
int main() {
  int count;
  int i;
  while (true) {
     cout << "input numbers to sort: ";
     cin >> count;
    if (count == 0) {
      cout << "quit" << endl;
      exit(0);
    }
    if (count > sizeof(num)) {
      cout << "num oversized" << endl;
      exit(-1);
    }
    for (i = 0; i < count; i++) {
      num[i] = rand() % 10000;
    }
    cout << "before sort:" << endl;
    for (i = 0; i < count; i++) {
       cout << num[i] << " ";
    }
    cout << endl;
    isort2(num, count); 
    cout << "after sort: " << endl;
    for (i = 0; i < count; i++) {
      cout << num[i] << " ";
    }
    cout << endl;
  }
  return 0;
}

