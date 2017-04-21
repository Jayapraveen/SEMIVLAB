/*
SERVER:
1.	Create socket for server using socket()
2.	Bind the socket with the port number specified as command line argument.
3.	Accept the connection request received from the client
4.	If the connection variable returns zero then the server accepts the connection request
5.	Read the message sent to the server
6.	Enter and write the message to the client
*/
//UDPchatSERVER
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main(int argc,char*argv[])
{
int i,sockfd,newsockfd,clilen,n,a=1;
struct sockaddr_inserv_addr,cliaddr;
char buffer[256];
if(argc!=2)
{
fprintf(stderr,"\nError!NoportProvided\n");
exit(1);
}
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
printerror("\nErrorOpeningSocket");
else
printf("\nSocketSuccessfullyCreated");
bzero((char*)&serv_addr,sizeof(serv_addr));
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
serv_addr.sin_port=htons(atoi(argv[1]));
if(bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
printerror("\nErrorinBinding");
listen(sockfd,5);
clilen=sizeof(cliaddr);
newsockfd=accept(sockfd,(struct sockaddr*)&cliaddr,&clilen);
if(newsockfd<0)
printerror("\nErroronaccept");
while(a!=0)
{
bzero(buffer,256);
n=read(newsockfd,buffer,255);
if(n<0)
printerror("\nErrorreadingfromsocket\n");
printf("\nMsgrecievedatserver:%s",buffer);
printf("\nEnterthemessagetobesent");
gets(buffer);
n=write(newsockfd,buffer,50);
if(n<0)
printerror("\nErrorwritinginsocket\n");
if(strcmp(buffer,"stop")==0)
a=0;
}
}
int printerror(char*msg)
{
perror(msg);
exit(1);
}
