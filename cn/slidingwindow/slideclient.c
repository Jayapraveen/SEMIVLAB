/*
CLIENT:
1.	Create socket for the receiver using socket()
2.	Comment the server using port number
3.	Read frames sent by the server and check if the frames are being transmitted correctly
4.	If no, send error to the server and read the re-transmitted frame
5.	Read the sequence where error has occurred
6.	If “exit” then close socket().
*/

//SLIDING WINDOW CLIENT
#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
int main(int argc,char *argv[])
{
int i,sockfd,connfd,choice,n,a=1;
struct sockaddr_in serv_addr,cli_addr;
char buffer[256],str[10],str1[10],err[10];
if(argc!=3)
{
fprintf(stderr,"Type %s followed by host name and the port number \n",argv[0]);
exit(0);
}
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
{
printerror("\n Error opening Socket");
exit(0);
}
else
printf("\n Socket successfully created\n");
bzero((char *)&serv_addr,sizeof(serv_addr));
serv_addr.sin_family=AF_INET;
serv_addr.sin_port=htons(8246);
serv_addr.sin_addr.s_addr=INADDR_ANY;
connect(sockfd,&serv_addr,sizeof(serv_addr));
for(;;)
{
read(sockfd,str,20);
if(!strcmp(str,"exit"))
{
printf("\n Exiting");
break;
}
printf("Received %s\n",str);
printf("Do you want to report error(1-yes,0-no)");
scanf("%d",&choice);
if(!choice)
write(sockfd,"-1",sizeof(-1));
else
{
printf("Enter the sequence no.of frames where error have occurred ");
scanf("%s",err);
write(sockfd,err,sizeof(err));
read(sockfd,str,20);
printf("Recieved the Retransmitted String %s",str);
}
}
}
int printerror(char *msg)
{
perror(msg);
}
