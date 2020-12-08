//
// implement the qsort by myself
// i prefer the version of bash+len
//

#include <iostream>
using namespace std;

void swap(int *left, int *right) {
  int tmp = *left;
  *left = *right;
  *right = tmp;
} 

// perfer version
void qsort2(int *base, size_t len) {
  if (len == 1) {
    return;
  } else if (len == 2) {
    if (base[0] > base[1]) {
      swap(base, base + 1);
    }
    return;
  }
  size_t mid = len / 2;
  if (base[0] > base[len - 1]) {
    swap(base, base + len - 1);
  }
  if (base[mid] > base[len - 1]) {
    swap(base + mid, base + len - 1);
  }
  if (base[mid] < base[0]) {
    swap(base + mid, base);
  }
  int pivot = base[mid];
  swap(base + mid, base + len - 2);
  size_t left = 0;
  size_t right = len - 2;
  for(;;) {
    while (base[++left] < pivot){};
    while (base[--right] > pivot){};
    if (left < right) {
      swap(base + left, base + right);
    } else {
      break;
    }
  }
  swap(base + left, base + len - 2);
  qsort2(base, left);
  qsort2(base + left + 1,  len - left - 1);
}

void qsort3(int *base, size_t first, size_t last) {
  if (first == last) {
    return;
  }
  if (first + 1 == last) {
    if (base[first] > base[last]) {
      swap(base + first, base + last);
    }
    return;
  }
      
  size_t mid = (first + last) / 2;
  if (base[first] > base[last]) {
    swap(base + first, base + last);
  }
  if (base[mid] > base[last]) {
    swap(base + mid, base + last);
  }
  if (base[mid] < base[first]) {
    swap(base + mid, base + first);
  }
  int pivot = base[mid];
  swap(base + mid, base + last - 1);
  size_t left = first;
  size_t right = last - 1;
  for(;;) {
    while (base[++left] < pivot){};
    while (base[--right] > pivot){};
    if (left < right) {
      swap(base + left, base + right);
    } else {
      break;
    }
  }
  swap(base + left, base + last - 1);
  qsort3(base, first, left - 1);
  qsort3(base, left + 1, last);
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
    qsort2(num, count);
    // qsort3(num, 0, count - 1);
    // isort2(num, count); 
    cout << "after sort: " << endl;
    for (i = 0; i < count; i++) {
      cout << num[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
