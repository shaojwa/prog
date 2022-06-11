#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <netdb.h>
#include <iostream>
using namespace std;

void error(string msg) 
{
  perror(msg.data());
  exit(1);
}

int launch_server(int port_no) {
  int sockfd, newsockfd, portno, client_len, n;
  char buffer[256];
  struct sockaddr_in server_addr, client_addr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    error("error: opening socket");
  }
  bzero((char*)&server_addr, sizeof(server_addr));
  portno = port_no;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(portno);
  server_addr.sin_addr.s_addr = INADDR_ANY;
  if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    error("error: on binding");
  }
  cout << "listening..." << endl;
  listen(sockfd, 5);
  client_len = sizeof (client_addr);
  newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t *)&client_len);
  if (newsockfd < 0) {
    error("error: on accept");
  }
  bzero(buffer, 256);
  n = read (newsockfd, buffer, 255);
  if (n < 0) {
    error("error: reading from socket");
  }
  printf("recv: %s\n", buffer);
  n = write(newsockfd, "server ack\n", 12);
  if (n < 0) error("error: writing to socket");
  sleep(10);
  return 0;
}


int start_client(char* host_name, int port_no) {
  int sockfd, portno, n;
  char buffer[256];
  struct sockaddr_in server_addr;
  struct hostent *server;
  portno = port_no;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    error("error: opening socket");
  }
  server = gethostbyname(host_name);
  if (server == NULL) {
    fprintf(stderr, "error: no such host\n");
    exit(1);
  }

  bzero((char*)&server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
  server_addr.sin_port = htons(portno);
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    error("error: connecting");
  }
  printf("please enter the message: ");
  bzero(buffer, 256);
  fgets(buffer, 255, stdin);
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    error("error: write to socket");
  }

  bzero(buffer, 256);
  n = read(sockfd, buffer, 255);
  if (n < 0) {
    error("error: read from socket");
  }
  printf("%s\n", buffer);
  return 0;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    cout << "usage: sock-test { s| c <server> <port> }" << endl;
    exit(-1);
  }
  if (strcmp(argv[1], "c") == 0) {
    if (argc != 4) {
      cout << "usage: sock-test { s| c <server> <port> }" << endl;
      exit(-1);
    }
    cout << "start client, connect to server: " << argv[2] << ", at port " << argv[3] << endl;
    start_client(argv[2], stoi(argv[3])); 
  } else if (strcmp(argv[1], "s") == 0) {
    launch_server(1102);
  } else {
    cout << "usage: sock-test { s| c <server> <port> }" << endl;
    exit(-1);
  }
  return 0;
}
