#include <stdio.h>
#include <math.h>

double results[256*1024];

int main()
{
  unsigned long long n;
  unsigned int count = 0;
  while(-1 != scanf("%lld", &n)) {
    results[count++] = pow(n, 0.5);
  }
  while (count--) {
   printf("%.4lf\n", results[count]);
  }
  return 0;
} 
