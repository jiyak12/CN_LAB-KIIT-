#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    int socket_descriptor = socket(AF_INET, SOCK_DGRAM, 0);
    if(socket_descriptor == -1) {
        printf("Socket creation failed\n");
    } else {
        printf("Socket created successfully\nSocket descriptor: %d\n", socket_descriptor);
    }
    struct sockaddr_in server_address = {
        .sin_family = AF_INET,
        .sin_port = 80,
        .sin_addr.s_addr = 0,
    };
    int b_check = bind(socket_descriptor, (struct sockaddr *) &server_address, sizeof(server_address));
    if(b_check == -1) {
        printf("Bind failed\n");
    } else {
        printf("Bind successful\n");
    }
}
