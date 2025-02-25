#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_PATH "/tmp/unix_socket_3260"

int main() {
    int client_sock;
    struct sockaddr_un server_addr;
    char buffer[256];

    client_sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (client_sock == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sun_family = AF_UNIX;
    strcpy(server_addr.sun_path, SOCKET_PATH);

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
