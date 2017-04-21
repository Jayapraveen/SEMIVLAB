/*
SERVER:
1.	Check if the number of arguments is less than two and if so throw an error
2.	Get the socket using socket() function of tcp , check if the value is less than zero and if it is not  less then call bzero function to clear the buffer
3.	Assign the values to the structure members and then call the bind message function to bind the socket
4.	Listen for the connection and if there is a connection accept it 
5.	Get the message from the client and display it.
*/

//UDPechoSERVER
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char*argv[])
{
int i,sockfd,newsockfd,clilen,n;
struct sockaddr_inserv_addr,cliaddr;
char buffer[256];
if(argc!=2)
{
fprintf(stderr,"\nError!NoportProvided\n");
exit(1);
}
sockfd=socket(AF_INET,SOCK_DGRAM,0);
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
clilen=sizeof(cliaddr);
while(1)
{
bzero(buffer,256);
n=recvfrom(sockfd,buffer,255,0,(struct sockaddr*)&cliaddr,&clilen);
if(n<0)
printerror("\nErrorreadingfromsocket\n");
printf("\nMsgrecievedatserver:%s",buffer);
n=sendto(sockfd,buffer,255,0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));
if(n<0)
printerror("\nErrorwritinginsocket\n");
}
return 0;
}
int printerror(char*msg)
{
perror(msg);
exit(1);
}
