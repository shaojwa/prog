#include <iostream>
using namespace std;

// test array initialization by zero
int main()
{

  int array[10] = {0};
  int i = 0;
  while(i < 10) {
    cout << array[i++] << endl;
  }
  return 0;
}
