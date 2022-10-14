#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#define PORT 8080
#define MAXLINE 1024

int main()
{
    int sockfd;
    char buffer[MAXLINE];
    char *hello="Hello from server";
    
    int count=1;
    struct sockaddr_in servaddr,cliaddr;

    if((sockfd=socket(AF_INET,SOCK_DGRAM,0))<0)
    {
       perror("Socket creation failed");
       exit(EXIT_FAILURE);
    }

    memset(&servaddr,0,sizeof(servaddr));
    memset(&cliaddr,0,sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if(bind(sockfd,(const struct sockaddr*)&servaddr,sizeof(servaddr))<0)
    {
         perror("Bind failed");
         exit(EXIT_FAILURE);
    }

    int len,n;
    len = sizeof(cliaddr);
    n = recvfrom(sockfd,(char*)buffer,MAXLINE,0,(struct sockaddr*)&cliaddr,&len);
    buffer[n]='\0';
    printf("Client : %s\n",buffer);
    for(int i=0;buffer[i]!='\0';i++)
    {
         if(buffer[i]==' '&&buffer[i+1]!=' ')
             count++; 
    }
    sendto(sockfd,&count,4,0,(struct sockaddr*)&cliaddr,len);
    printf("Number of words sent by server.\n");

    return 0;
}    	
