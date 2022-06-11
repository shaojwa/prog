#include <iostream>
using namespace std;

#define ROUND_UP_128(x) (-(-(x) & -128))
int main() {
 int p = 259;
 cout << ROUND_UP_128(p) << endl;
 return 0;
}
