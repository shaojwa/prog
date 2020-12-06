#include <iostream>
using namespace std;

class dog {
    static constexpr bool matrix[][] {
        {false, true}, {true, false}
    }
    int name;
}

int main()
{
    dog d;
    cout << "a.matrix[0][0] " << d.matrix[0][0] << endl;
    return 0;
}
