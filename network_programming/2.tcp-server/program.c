#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>

#define PORT 18000
#define MAX_BUFFER_SIZE 1024

int main() {
    int sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    char response[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, World!</h1></body></html>";
    char ipaddress [150];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to address and port
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(sockfd, 5) < 0) {
        perror("Failed to listen for connections");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n type localhost:18000 on browser\n", PORT);

    while (1) {
        // Accept incoming connection
        client_len = sizeof(client_addr);
        client_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_len);
        if (client_sockfd < 0) {
            perror("Failed to accept connection");
            exit(EXIT_FAILURE);
        }

        // printing ip address from where request is coming
        // IT CONVERT IP ADDRESS BINARY REPRESENTATION TO NORMAL REPRESENTATION
        const char* result = inet_ntop(AF_INET, &(client_addr.sin_addr), 
                                    ipaddress, sizeof(ipaddress));
        if (result == NULL) {
            perror("Failed to convert IP address");
            exit(EXIT_FAILURE);
        }

    printf("IP address: %s\n", ipaddress);
        // Send response to client
        if (send(client_sockfd, response, sizeof(response), 0) < 0) {
            perror("Failed to send response");
            exit(EXIT_FAILURE);
        }

        // Close client socket
        close(client_sockfd);
    }

    // Close server socket
    close(sockfd);

    return 0;
}
