#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <pthread.h> 

#include "parser.h"
#include "helper.h"

#define PORT 8080
#define MAX_LINE 4

robotVals *r;

// Thread for preparation to move the robot when r's id changes
void* StartMove(void* vargp) {
    int prevRobotId = -1;
    printf("\tThread is on! ... \n");
    while(1) {
        if(prevRobotId != r->id) {
            printf("\tChanging directions ...");
            printf("%f %f %f 0x%02x 0x%08x\n", r->dx, r->dy, r->angle, r->flags, r->id);
            prevRobotId = r->id;
        }
    }
    return NULL;
}

int main() {
    int sockfd, n;
    int buffer[MAX_LINE];
    socklen_t len;
    char msg[] = "am client";
    pthread_t tid;

    struct sockaddr_in servaddr;
    
    printf("Starting client ...\n");
    r = calloc(1, sizeof(robotVals));
    check(sockfd = socket(AF_INET, SOCK_DGRAM, 0));
    printf("Finished checks ...\n");

    printf(" ... \n");
    memset(&servaddr, 0, sizeof(servaddr));

    // setting up server
    printf(" ... \n");
    servaddr.sin_port = htons(PORT);
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    len = sizeof(servaddr);

    // Sending message to server
    printf("Sending msg to server ... \n");
    sendto(sockfd, (const char *)msg, strlen(msg), 
        0, (const struct sockaddr *) &servaddr,  
            len); 
    printf("Msg sent to server ... \n");

    //Creating a thread for movement
    printf("Creating thread ... \n");
    pthread_create(&tid, NULL, StartMove, NULL);
    printf("Thread created ... \n");

    // Reading input from server
    while(1) {
        printf("\nWaiting for input ...\n");
        n = recvfrom(sockfd, buffer, sizeof(buffer), 0, 
            (struct sockaddr *) &servaddr, &len);
        printf("n set, checking ... \n");
        if(n < 0)
            continue;
        printf("Input received, parsing ...\n");
        printBuffer(buffer);
        parse(buffer, &r);
        printf("%f %f %f 0x%02x %d\n", r->dx, r->dy, r->angle, r->flags, r->id);
    }

    // if it quits, free up the space and quit
    free(r);
    return 0;
}

void printBuffer(int* buffer) {
    int i;
    for(i = 0; i < 3; i++)
        printf("%d ", buffer[i]);
    printf("0x%08x\n", buffer[3]);
}

void parse(int* buffer, robotVals **r) {
    int i;
    robotVals *tempR;
    checkPointer(tempR = calloc(1, sizeof(robotVals)));

    tempR->dx = buffer[0];
    tempR->dy = buffer[1];
    tempR->angle = buffer[2];

    tempR->flags = (uint8_t) getValuesFromInt(0, sizeof(uint8_t), buffer[3]);
    tempR->id = (uint16_t) getValuesFromInt(8, sizeof(uint16_t), buffer[3]);

    printf("%f %f %f 0x%02x 0x%08x\n", tempR->dx, tempR->dy, tempR->angle, tempR->flags, tempR->id);

    if(tempR->id > (*r)->id || (*r)->id == 0)
        *r = tempR;
}