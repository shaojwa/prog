#include<sys/stat.h>
#include<errno.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("usage: %s <path to file/dir>\n", argv[0]);
    exit(0);
  }
  struct stat buffer;
  int status;
  status = stat(argv[1], &buffer);
  if (status == -1) {
    printf("eror: %d\n", errno);
    exit(-1);
  }

  printf("stat.st_ino = %d\n", buffer.st_ino);
  printf("stat.st_nlink = %d\n", buffer.st_nlink);
  printf("stat.st_size = %d\n", buffer.st_size);
  printf("stat.st_blocks = %d\n", buffer.st_blocks);
  printf("stat.st_blksize = %d\n", buffer.st_blksize);
  return 0;
}
