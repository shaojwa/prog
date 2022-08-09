#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <errno.h>
#include <error.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

int main(void) {
  int fd, size;
  struct sockaddr_un un;
  un.sun_family = AF_UNIX;
  strcpy(un.sun_path, "unisock.unisok");
  if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
    error_at_line(-1, errno, __FILE__, __LINE__, "socket failed, errno: %d", errno);
  }
  size = offsetof(struct sockaddr_un, sun_path) + strlen(un.sun_path);
  if (bind(fd, (struct sockaddr *)&un, size) < 0) {
    error_at_line(-1, errno, __FILE__, __LINE__, "socket failed, errno: %d", errno);
  }
  printf("unix domain socket bound success\n");
  sleep(600);
  exit(0);
}
