/*
CLIENT:
1.	Find the send address of the website in the command line argument and send it to the server
2.	Receive the message from the client and then terminate with null character
3.	Display the string echo buffer
*/
// DNS CLIENT
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
int main(int argc,char *argv[])
{
int clilen,sockfd,n,a=1;
struct sockaddr_in serv_addr,cliaddr;
char buffer[256],str[10],str1[10];
if(argc!=3)
{
fprintf(stderr,"Type %s followed by host name and the port no.\n",argv[0]);
exit(0);
}
sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(sockfd<0)
{
printerror("\nError opening the socket\n");
exit(0);
}
else
{
printf("\nSocket successfully created\n");
bzero((char *)&serv_addr,sizeof(serv_addr));
serv_addr.sin_family=AF_INET;
serv_addr.sin_port=htons(atoi(argv[1]));
serv_addr.sin_addr.s_addr=htonl(atoi(argv[2]));
clilen=sizeof(serv_addr);
while(a!=0)
{
bzero(buffer,256);
printf("Enter the domain name\n");
scanf("%s",buffer);
n=sendto(sockfd,buffer,strlen(buffer),0,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
if(n<0)
printerror("\nError writing to socket\n");
bzero(buffer,256);
printf("Server's message:");
n=recvfrom(sockfd,buffer,255,0,(struct sockaddr *)&serv_addr,&clilen);
if(n<0)
printerror("error reading from socket\n");
printf("The IP address is %s\n",buffer);
if(strcmp(buffer,"stop")==0)
a=0;
}
}
return 0;
}
int printerror(char *msg)
{
perror(msg);
}
