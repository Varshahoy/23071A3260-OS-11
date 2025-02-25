
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_PATH "/tmp/unix_socket_3260"

int main() {
    int server_sock, client_sock;
    struct sockaddr_un server_addr, client_addr;
    socklen_t client_len;
    char buffer[256];

    server_sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sun_family = AF_UNIX;
    strcpy(server_addr.sun_path, SOCKET_PATH);
    unlink(SOCKET_PATH); // Remove if the file exists

    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    listen(server_sock, 5);
    printf("Server listening on UNIX socket...\n");

    client_len = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_len);
    if (client_sock == -1) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        read(client_sock, buffer, sizeof(buffer));
        printf("Client: %s\n", buffer);
        if (strcmp(buffer, "exit") == 0) break;

        printf("Server: ");
        fgets(buffer, sizeof(buffer), stdin);
        write(client_sock, buffer, strlen(buffer));
    }

    close(client_sock);
    close(server_sock);
    unlink(SOCKET_PATH);
    return 0;
}
