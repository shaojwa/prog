
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAXPENDING 5 /* Max connection request */

void Die(char *msg) { perror(msg); exit(1); }

int clientsock;
struct sockaddr_in echoclient;

int sockserver;
struct sockaddr_in echoserver;

int start_listen() {

    printf("start listen.\n");
    if ((sockserver = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        Die("Failed to create socket");
    }
    printf("create socket success. (socket = %d)\n", sockserver);

    memset(&echoserver, 0, sizeof(echoserver));
    echoserver.sin_family = AF_INET;
    echoserver.sin_addr.s_addr = htonl(INADDR_ANY);
    echoserver.sin_port = htons(1102);
    if (bind(sockserver, (struct sockaddr *) &echoserver,
             sizeof(echoserver)) < 0) {
        Die("Failed to bind the server socket");
    }
    printf("bind socket success.\n");

    if (listen(sockserver, MAXPENDING) < 0 ) {
        Die("Failed to listen on server socket");
    }
    printf("listen socket success.\n");
}

int process() {

    unsigned int clientlen = sizeof(echoclient);
    if ((clientsock = accept(sockserver,
                    (struct sockaddr *)&echoclient, &clientlen)) < 0 ) {
        Die("Failed to accept client connetion");
    }
}

int main() {
    start_listen();
    process();
    return 0;
}
