#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 3260
#define SERVER_IP "127.0.0.1"

int main() {
    int client_sock;
    struct sockaddr_in server_addr;
    char buffer[256];

    client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(client_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Client: ");
        fgets(buffer, sizeof(buffer), stdin);
        write(client_sock, buffer, strlen(buffer));

        if (strcmp(buffer, "exit\n") == 0) break;

        memset(buffer, 0, sizeof(buffer));
        read(client_sock, buffer, sizeof(buffer));
        printf("Server: %s\n", buffer);
    }

    close(client_sock);
    return 0;
}
