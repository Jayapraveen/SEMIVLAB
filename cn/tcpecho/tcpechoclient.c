/*
CLIENT:
1.	Check if the number of arguments is less than two and if so throw an error
2.	Get the port number and the socket
3.	Use the gethostname(parameter) method to get host
4.	Clear the buffer and then assign the family to AF_INET
5.	Copy the message to the buffer using bcopy method
6.	Connect to the server and prompt the user to enter the message and then pass the message to the server.
7.	Copy the message from the buffer and display the message from the buffer.
*/
//TCPechoCLIENT
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
if(argc!=3)
{
fprintf(stderr,"Type%sfollowedbyhostnameandtheportnumber\n",argv[0]);
exit(0);
}
sockfd=socket(AF_INET,SOCK_STREAM,0);
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
if(connect(sockfd,&serv_addr,sizeof(serv_addr))<0)
printerror("\nErrorConnecting");
for(;a!=0;)
{
printf("|nPleaseenterthemessage\n");
bzero(buffer,256);
scanf("%s",buffer);
n=write(sockfd,buffer,strlen(buffer));
if(n<0)
printerror("\nErrorwritingtothesocket");
bzero(buffer,256);
printf("\nServerecho'smessage");
n=read(sockfd,buffer,255);
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
