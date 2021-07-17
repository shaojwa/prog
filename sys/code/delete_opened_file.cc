#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <iostream>
#include <string.h>

using namespace std;

char buf[] = "test\n";
int main() {
    int fd = open("/home/wsh/out.log", O_RDWR);
    cout << "fd " << fd << endl;
    if (fd == -1) {
        cout << "errno " << errno <<endl;
    }
    while(true) {
        sleep(10);
        ssize_t ret = write(fd, buf, strlen(buf));
        cout << "write " << ret << endl;
    }
    return 0;
}
