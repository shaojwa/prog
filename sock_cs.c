#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <netdb.h>


void error(char *msg) 
{
  perror(msg);
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
  printf("here is the message: %s\n", buffer);
  n = write(newsockfd, "i got your message\n", 20);
  if (n < 0) error("error: writing to socket");
  sleep(60);
  return 0;
}


int start_client(char* host_name, int port_no) {
  int sockfd, portno, n;
  char buffer[256];
  struct sockaddr_in server_addr;
  struct hostent *server;
  int width = 3;
  int num = 10;
  printf("----%*d\n", width, num);
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

int main(void) {
  launch_server(1102);
  return 0;
}
