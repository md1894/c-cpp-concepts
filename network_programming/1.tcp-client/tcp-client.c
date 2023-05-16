#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include<unistd.h>

#define MAX_BUFFER_SIZE 4096
#define HOSTNAME "www.google.com"
#define PORT 80

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Get server IP address
    host = gethostbyname(HOSTNAME);
    if (host == NULL) {
        perror("Failed to get server IP address");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to the server");
        exit(EXIT_FAILURE);
    }

    // Send HTTP GET request
    const char *request = "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Failed to send HTTP GET request");
        exit(EXIT_FAILURE);
    }

    // Receive and print the response
    char buffer[MAX_BUFFER_SIZE];
    int num_bytes;
    while ((num_bytes = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[num_bytes] = '\0';
        printf("%s", buffer);
    }

    if (num_bytes < 0) {
        perror("Failed to receive response");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close(sockfd);

    return 0;
}
