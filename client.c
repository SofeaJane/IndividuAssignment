//client
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

int main(){
    
    struct sockaddr_in server,client;
    int sock_fd,n;
    char b1[100],b2[100];
    
    sock_fd = socket(AF_INET,SOCK_DGRAM,0);
    
    server.sin_family=AF_INET;
    server.sin_port=htons(53);
    server.sin_addr.s_addr=inet_addr("192.168.56.108");
    
    n=sizeof(server);
    
    printf("\nEnter domain name: ");
    scanf("%s",b2);
    sendto(sock_fd,b2,sizeof(b2),0,(struct sockaddr *)&server,n);
    recvfrom(sock_fd,b1,sizeof(b1), 0,NULL,NULL);
    printf("%s \n",b1);
    
    return 0;
}
