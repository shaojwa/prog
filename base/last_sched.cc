#include <iostream>
#include <unistd.h>
using namespace std;

int seconds = 10000;
int main() {
    cout << "mypid: " << getpid() << endl;
    while(true) {
        cout << "sleep " << seconds << "s" << endl;
        sleep(seconds);
    }
}
