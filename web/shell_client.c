#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

#define PORT 8080
#define BUFFER_SIZE 1024


void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr_list[0], 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    while (1) { // Add a loop to keep the connection open
        printf("> ");
        bzero(buffer,BUFFER_SIZE);
        fgets(buffer,BUFFER_SIZE - 1,stdin);

        // If the user enters "exit", break the loop
        if (strncmp(buffer, "exit", 4) == 0) {
            n = write(sockfd,buffer,strlen(buffer));
            if (n < 0) 
                error("ERROR writing to socket");
            break;
        }

        // If the buffer is empty or contains just a newline, continue to the next iteration
        // TODO read from the buffer and check if it's empty or contains just a newline
        if (buffer[0] == '\0' || (buffer[0] == '\n' && buffer[1] == '\0')) {
            continue;
        }

        n = write(sockfd,buffer,strlen(buffer));
        if (n < 0) 
            error("ERROR writing to socket");

        bzero(buffer,BUFFER_SIZE);
        n = read(sockfd,buffer,BUFFER_SIZE - 1);
        if (n < 0) 
            error("ERROR reading from socket");

        printf("%s\n",buffer);
    }

close(sockfd);
return 0;
}