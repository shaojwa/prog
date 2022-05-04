#include <iostream>
#include <cmath>
#include <stack>
#include <iomanip>
using namespace std;

int main()
{
  long long n;
  stack<double> stk;
  while(cin >> n) {
    stk.push(sqrt(n));
  }

  while (stk.size()) {
    cout << fixed << setprecision(4) << stk.top() << endl;
    stk.pop();
  }
  return 0;
} 
