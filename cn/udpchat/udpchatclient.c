/*
CLIENT:
1.	Create socket for client using socket()
2.	Send connection request to server
3.	Enter and write the message to be sent
4.	Read the message from the server
5.	If the buffer contains “exit” then the client is terminating.
6.	Close the socket.
*/

//UDPchatCLIENT

#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
int main(int argc,char*argv[])
{
int i,sockfd,connfd,n,a=1;
struct sockaddr_inserv_addr,cli_addr;
char buffer[256],str[10],str1[10];
int clilen;
if(argc!=3)
{
fprintf(stderr,"Type%sfollowedbyhostnameandtheportnumber\n",argv[0]);
exit(0);
}
sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(sockfd<0)
{
printerror("\nErroropeningSocket");
exit(0);
}
else
{
printf("\nSocketsuccessfullycreated\n");
bzero((char*)&serv_addr,sizeof(serv_addr));
serv_addr.sin_family=AF_INET;
serv_addr.sin_port=htons(atoi(argv[1]));
serv_addr.sin_addr.s_addr=htonl(atoi(argv[2]));
clilen=sizeof(serv_addr);
while(a!=0)
{
printf("|nPleaseenterthemessage\n");
bzero(buffer,256);
fgets(buffer,255,stdin);
n=sendto(sockfd,buffer,strlen(buffer),0,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
if(n<0)
printerror("\nErrorwritingtothesocket");
bzero(buffer,256);
printf("\nServerecho'smessage");
n=recvfrom(sockfd,buffer,255,0,(struct sockaddr*)&serv_addr,&clilen);
if(n<0)
printerror("\nErrorreadingfromsocket");
printf("%s",buffer);
if(strcmp(buffer,"stop")==0)
a=0;
}
return0;
}
}
int printerror(char*msg)
{
perror(msg);
exit(0);
}
