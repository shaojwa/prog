#include <cmath>
#include <stack>
#include <iostream>

int main()
{
  long long n;
  std::stack<double> stk;
  while(-1 != scanf("%lld", &n)) {
    stk.push(pow(n, 0.5));
  }
  while (stk.size()) {
   printf("%.4lf\n", stk.top());
    stk.pop();
  }
  return 0;
} 
