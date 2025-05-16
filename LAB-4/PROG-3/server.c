#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int checkPalindrome(char* str) {
    int n = 0;
    for (int i = 0; i < 1024; i++) {
        if(str[i] == '\0') {
            break;
        }
        n++;
    }
    int l = 0, r = n-1;
    while(l<=r) {
        if(str[l] != str[r]) return 0;
        l++;r--;
    }
    return 1;
}

int main() {
    // Create Socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) printf("Socket Creation Failed.\n");
    else printf("Socket Created Successfully.\n");

    // Bind Socket
    struct sockaddr_in serverAddr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = 0,
    };
    struct sockaddr_in clientAddr;
    int isBind = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if(isBind<0) printf("Socket Bind Failed.\n");
    else printf("Socket Bind Successfull.\n");

    // Listen
    int isListen = listen(sockfd, 5);
    if(isListen<0) printf("Listen Failed.\n");
    else printf("Listening...\n");

    // Accept
    socklen_t clientAddrLen = sizeof(clientAddr);
    int newsockfd = accept(sockfd, (struct sockaddr*)&clientAddr, &clientAddrLen);
    if(newsockfd<0) printf("Accept Failed.\n");
    else printf("Connection from Client Accepted.\n");

    // Recieve Message
    char buffer[1024] = {'\0'};
    int isRecv = recv(newsockfd, buffer, 1024, 0);
    if(isRecv<0) printf("Message couldn't be recieved.\n");
    else printf("Message Recieved: %s\n", buffer);

    // Process Message
    int isPalindrome = checkPalindrome(buffer);

    // Send Message
    int isSent = send(newsockfd, &isPalindrome, sizeof(isPalindrome), 0);
    if(isSent<0) printf("Message couldn't be sent.\n");
    else printf("Message Sent Successfully.\n");

    // Close
    close(newsockfd);
    close(sockfd);
    return 0;
}
