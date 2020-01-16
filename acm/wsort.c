#include <stdio.h>
#include <stdlib.h>

void swap(int *left, int *right) {
  int tmp = *left;
  *left = *right;
  *right = tmp;
}

void wsort(int *base, size_t first, size_t last) {
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
  wsort(base, first, left - 1);
  wsort(base, left + 1, last);
}

int num[10000];
int main() {
  int count;
  int i;
  while (printf("input num to sort: ") && scanf("%d", &count)) {
    if (count == 0) {
      printf("quit\n");
      exit(0);
    }
    if (count > sizeof(num)) {
      printf("num oversized\n");
      exit(-1);
    }
    for (i = 0; i < count; i++) {
      num[i] = rand() % 10000;
    }
    printf("before sort:\n");
    for (i = 0; i < count; i++) { printf("%d ", num[i]); }
    printf("\n");
    wsort(num, 0, count - 1);
    printf("after sort:\n");
    for (i = 0; i < count; i++) { printf("%d ", num[i]); }
    printf("\n");
  }
  return 0;
}
