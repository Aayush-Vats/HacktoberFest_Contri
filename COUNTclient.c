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
   char *st;
   int count;
   struct sockaddr_in servaddr;

   if((sockfd=socket(AF_INET,SOCK_DGRAM,0))<0)
   {
       perror("Socket creation failed");
       exit(EXIT_FAILURE);
   }

   memset(&servaddr,0,sizeof(servaddr));
   
   servaddr.sin_family = AF_INET;
   servaddr.sin_addr.s_addr = INADDR_ANY;
   servaddr.sin_port = htons(PORT);

   int n,len;
   printf("\nEnter the sentence:");
   scanf("%[^\n]s",st);
   
sendto(sockfd,(const char*)st,strlen(st),0,(const struct sockaddr*)&servaddr,sizeof(servaddr));
   printf("Sentence sent by client\n");

   recvfrom(sockfd,&count,4,0,(struct sockaddr*)&servaddr,&len);
   
   printf("Number of words: %d\n",count);

   close(sockfd);
   return 0;
}   
