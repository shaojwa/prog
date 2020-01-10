#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define  MEMSIZE (512*1024*1024)
int test_shmem()
{
  int shmid;
  char *ptr;
  pid_t pid;
  struct shmid_ds buf;
  int ret;
  shmid = shmget(IPC_PRIVATE, MEMSIZE, 0600);
  if (shmid == -1) {
    perror("shmget()");
    exit(1);
  }
  ret = shmctl(shmid, IPC_STAT, &buf);
  if (ret == -1) {
    perror("shmctl()");
    exit(1);
  }
  printf("shmid %d\n", shmid);
  printf("shmsize %zu\n", buf.shm_segsz);
  buf.shm_segsz *= 2;
  ret = shmctl(shmid, IPC_SET, &buf);
  if (ret == -1) {
    perror("shmctl()");
    exit(1);
  }
  printf("shmid %d\n", shmid);
  printf("shmsize %zu\n", buf.shm_segsz);
  pid = fork();
  if (pid < 0) {
    perror("fork()");
    exit(1);
  }
  if (pid == 0){
    ptr = (char *)shmat(shmid, NULL, 0);
    if (ptr == (void *)-1) {
      perror("shmat()");
    }
    bzero(ptr, MEMSIZE);
    strcpy(ptr, "hello");
    exit(0);
  } else {
    wait(NULL);
    ptr = (char *)shmat(shmid, NULL, 0);
    if (ptr == (void*)-1) {
      perror("shmat()");
      exit(1);
    }
    puts(ptr);
    exit(0);
  }
}

int main(void) {
  test_shmem();
  return 0;
}
