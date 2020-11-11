#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int num = 5;
    const int *cp = &num;
    int *ncp = (int *)cp;
    *ncp = 10;
    cout << cp << ", " << ncp << endl;
    cout << "num " << num << endl;
    cout << "cp " << *cp << endl;
    cout << "ncp " << *ncp << endl;
    cout << cp << ", " << ncp << endl;
    return 0;
}
