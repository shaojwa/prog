#include <iostream>

using  namespace std;

int main() {
    uint64_t a, b;
    uint8_t  c = 0;
    a = 100;
    b = 4;
    c = a / b;
    cout << "uint64_t(c) " << (unsigned char)(c) << endl;
    cout << "static_cast<uint16_t>(c) " << static_cast<uint16_t>(c) << endl;
    return 0;
}
