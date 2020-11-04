#include <stdio.h>
#include <stdlib.h>

void swap(int *left, int *right) {
  int tmp = *left;
  *left = *right;
  *right = tmp;
} 

// qsort
void ws_qsort_s(int *base, size_t first, size_t last) {
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
  wqsorts(base, first, left - 1);
  wqsorts(base, left + 1, last);
}

void ws_qsort_l(int *base, size_t length) {
  if (length == 1) {
    return;
  } else if (length == 2) {
    if (base[0] > base[1]) { swap(base, base + 1); }
    return;
  }
      
  size_t mid = length / 2;
  if (base[0] > base[length - 1]) {
    swap(base, base + length - 1);
  }
  if (base[mid] > base[length - 1]) {
    swap(base + mid, base + length - 1);
  }
  if (base[mid] < base[0]) {
    swap(base + mid, base);
  }
  int pivot = base[mid];
  swap(base + mid, base + length - 2);
  size_t left = 0;
  size_t right = length - 2;
  for(;;) {
    while (base[++left] < pivot){};
    while (base[--right] > pivot){};
    if (left < right) {
      swap(base + left, base + right);
    } else {
      break;
    }
  }
  swap(base + left, base + length - 2);
  wqsortl(base, left);
  wqsortl(base + left + 1,  length - left - 1);
}


// insert sort
void ws_insert_sort (int *base, size_t nmemb) {
  int i = 0, j = 0;
  for (i = 0; i < nmemb - 1; i++) {
    for (j = i + 1; j < nmemb; j++) {
      if (base[i] > base[j]){
        swap(base + i, base + j);
      }
    }
  }
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
    // ws_qsort_s(num, 0, count - 1);
    // wq_sort_l(num, count);
    ws_insert_sort(num, count); 
    printf("after sort:\n");
    for (i = 0; i < count; i++) { printf("%d ", num[i]); }
    printf("\n");
  }
  return 0;
}
