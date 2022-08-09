#include <iostream>
using namespace std;

//
//
int main() {
 uint32_t p = 259;
 cout << ~259 << endl; // -260, signed by default
 cout << ~p << endl; // 4294967036
 cout << uint32_t(~259)<< endl; // 4294967036 
 return 0;
}
