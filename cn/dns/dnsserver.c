/*
SERVER:
1.	Test for the current number of arguments.
2.	Create a UDP socket run the block to accept the connection forever
3.	Receive the source address from the receiver,for the client and then echo that address 
4.	Open the DNS file and then match the source address with the address of the file
5.	If the address is found,then display the address in the file using sendto()
6.	Catch the exception if any
*/
// DNS SERVER
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
int main(int argc,char *argv[])
{
int sockfd,n,a=1;
char buffer[256];
char name[256];
char ip[20];
struct sockaddr_in serv_addr,cliaddr;
int clilen;
FILE *fp1;
if(argc!=2)
{
fprintf(stderr,"\nPort not provided\n");
exit(0);
}
sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(sockfd<0)
printerror("\nError opening the socket\n");
else
printf("Socket successfully created\n");
bzero((char *)&serv_addr,sizeof(serv_addr));
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
serv_addr.sin_port=htons(atoi(argv[1]));
if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
printerror("\nError binding");
clilen=sizeof(cliaddr);
while(a!=0)
{
bzero(buffer,256);
n=recvfrom(sockfd,buffer,256,0,(struct sockaddr *)&serv_addr,&clilen);
if(n<0)
printerror("Error on reading from socket\n");
fp1=fopen("file.txt","r");
while(!feof(fp1))
{
fscanf(fp1,"%s%s",name,ip);
if(strcmp(buffer,name)==0)
{
printf("The name of the domain  is %s\n the device's IP address is %s\n",name,ip);
n=sendto(sockfd,ip,strlen(ip),0,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
if(n<0)
printerror("Error writing to socket");
}
}
fclose(fp1);
if(strcmp(buffer,"stop")==0)
a=0;
}
return 0;
}
int printerror(char *msg)
{
perror(msg);
}
