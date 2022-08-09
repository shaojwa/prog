
#include "advio.h"
#include <sys/select.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <poll.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;



#define READ_LEN (31)
#define cout cout << __func__ << ": " 

void  show_stdno_macro()
{
  cout << "STDIN_FILENO " << STDIN_FILENO << ", STDOUT_FILENO " << STDOUT_FILENO
    << ", STDERR_FILENO " << STDERR_FILENO << ", FS_SETSIZE " << FD_SETSIZE << endl;
}


int check_select_retval(const string &filename) 
{
  fd_set rset;
  FD_ZERO(&rset);
  int fd = open(filename.data(), O_RDWR);
  cout << "fd " << fd << endl;
  FD_SET(fd, &rset);
  FD_SET(STDIN_FILENO, &rset);
  FD_SET(STDOUT_FILENO, &rset);
  FD_SET(STDERR_FILENO, &rset);
  
  //
  fd_set wset;
  FD_ZERO(&wset);
  FD_SET(STDOUT_FILENO, &wset);
  FD_SET(fd, &wset);
  return select(fd + 1, &rset, &wset, 0, 0);
}



int read_part_select(const string &filename) 
{
  int fd = open(filename.data(), O_RDWR);
  if (fd == -1) {
    perror("open");
    exit(-1);
  }

  fd_set rset;
  FD_ZERO(&rset);
  FD_SET(fd, &rset);
  
  char buf[READ_LEN + 1];
  while(select(fd + 1, &rset, 0, 0, 0)) {
    int ret = read(fd, buf, READ_LEN);
    if (ret == -1) {
      cout << "err read: errno " << errno << endl;
      return ret;
    } else if (!ret) {
      cout << "end of file, ret " << ret << endl;
      return ret;
    }
    buf[ret] = 0;
    cout << "got " << ret << " bytes: " << buf << endl;
 }
  return 0;
}


// using poll to monitor fds with level-triggered
int read_part_poll(const string &filename) 
{
  int fd = open(filename.data(), O_RDWR);
  if (fd == -1) {
    perror("open");
    exit(-1);
  }

  struct pollfd fds[1];
  fds[0].fd = fd;
  fds[0].events = POLLIN;

  char buf[READ_LEN + 1];
  while(poll(fds, 1, -1)) {
    int ret = read(fd, buf, READ_LEN);
    if (ret == -1) {
      cout << "err read: errno " << errno << endl;
      return ret;
    } else if (!ret) {
      cout << "end of file, ret " << ret << endl;
      return ret;
    }
    buf[ret] = 0;
    cout << "got " << ret << " bytes: " << buf << endl;
 }
  return 0;
}


// using epoll to monitor fds with level-triggered
int read_part_epoll(const string &filename) 
{
  int fd = open(filename.data(), O_RDWR);
  char buf[READ_LEN + 1];
  int epollfd = epoll_create(1);

  if (epollfd == -1) {
    perror("epoll_create");
    exit(-1);
  }
 
  cout << "epollfd " << epollfd << endl;
  struct epoll_event ev, events[10];
  ev.events = EPOLLIN | EPOLLET;
  ev.data.fd = fd;
  //
  // regular file is not supported by epoll
  if (epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev) == -1) {
    perror("epoll_ctl: add fd");
    exit(-1);
  }

  while (true) {
    int nfds = epoll_wait(epollfd, events, 10, -1);
    if (nfds == -1) {
      perror("epoll_pwait");
      exit(-1);
    }

    for (int n = 0; n < nfds; ++n) {
      if (events[n].data.fd != fd) {
        perror("fd");
      }
      int ret = read(fd, buf, READ_LEN);
      if (ret == -1) {
        cout << "err read: errno " << errno << endl;
        return ret;
      } else if (!ret) {
        cout << "end of file, ret " << ret << endl;
        return ret;
      }
      buf[ret] = 0;
      cout << "got " << ret << " bytes: " << buf << endl;
    }
  }
  return 0;
}

