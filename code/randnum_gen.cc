#include <iostream>
using namespace std;

int constexpr max_count = 5;
int main() {
    cout << "RAND_MAX " << RAND_MAX << endl;
    int val = 0;
    int count = 0;
    cout << "---- no srand ---- " << endl;
    while (count++ < max_count) {
        val = rand();
        cout << "count " << count << ", rand " << val << endl;
    }
    cout << "---- srand(1) ---- " << endl;
    srand(1);
    count = 0;
    while (count++ < max_count) {
        val = rand();
        cout << "count " << count << ", rand " << val << endl;
    }
    cout << "---- srand(2) ---- " << endl;
    srand(2);
    count = 0;
    while (count++ < max_count) {
        val = rand();
        cout << "count " << count << ", rand " << val << endl;
    }

    cout << "---- rand_r ---- " << endl;
    uint32_t seed = 1;
    count = 0;
    while (count++ < max_count) {
        val = rand_r(&seed);
        cout << "count " << count << ", rand " << val << endl;
    }

    cout << "---- rand_r ---- " << endl;
    count = 0;
    seed = 1;
    while (count++ < max_count) {
        val = rand_r(&seed);
        cout << "count " << count << ", rand " << val << endl;
    }
    return 0;
    return 0;
}

