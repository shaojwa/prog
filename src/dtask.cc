#include <unistd.h>

int main(int argc, char* argv[]) {
  if (!vfork()) {
    sleep(100);
  }
  return 0;
}
