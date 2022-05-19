//server
#include<stdio.h>
#include <stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>

int main(){
    
    FILE *fp;
    struct sockaddr_in server,client;
    int sock_fd,n;
    char b1[100],b2[100],a[100];
    
    sock_fd = socket(AF_INET,SOCK_DGRAM,0);
    if(sock_fd < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Server Socket is created.\n");
	
	printf("Socket descriptor: %d \n" , sock_fd);
    
    memset(&server,0, sizeof(server));
    memset(&client,0, sizeof(client));
    
    server.sin_family=AF_INET;
    server.sin_port=htons(53);
    server.sin_addr.s_addr=INADDR_ANY;
    
    bind(sock_fd,(struct sockaddr *)&server,sizeof(server));
    n=sizeof(client);
    
    while(1)
    {
        strcpy(b2,"");
        fp=fopen("dns.txt","r");
        recvfrom(sock_fd,b1,sizeof b1, 0,(struct sockaddr *)&client,&n);
        while(!feof(fp))
        {
           fscanf(fp,"%s",a);
           if(strcmp(a,b1)==0)
          {
                fscanf(fp,"%s",b2);
                break;
          }
      }
      if(strcmp(b2,"")==0)
     {
           strcpy(b2,"Not found...");
      }
     fclose(fp);
     sendto(sock_fd,b2,sizeof b2,0,(struct sockaddr *)&client,n); 
    }
    return 0;
}
