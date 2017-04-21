/*
SERVER:
1.	Create a socket for the sender using socket()
2.	Bind the socket using bind() with the port number specified
3.	Enter the text to be transmitted
4.	Copy the texdt to frames
5.	Check for errors in the transmitted frame
6.	If no error is received print “transmission is successful”.
7.	Else display the error and retransmit the frame
8.	If “exit” , close the socket connection
*/
// SLIDING WINDOW SERVER
#include<netinet/in.h>
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
# define size 4
int main(int argc,char *argv[])
{
int sockfd,newsockfd,clilen,n,a=1,ch,len,i,status,j;
struct sockaddr_in serv_addr,cliaddr;
char frame[256],str[20],temp[20],ack[20];
if(argc!=2)
{
fprintf(stderr,"\n Error!No port Provided\n");
exit(1);
}
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
printerror("\n Error Opening Socket");
else
printf("\n Socket Successfully Created");
bzero((char *)&serv_addr,sizeof(serv_addr));
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
serv_addr.sin_port=htons(8246);
if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
printerror("\n Error in Binding");
listen(sockfd,5);
len=sizeof(&cliaddr);
newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr,&len);
if(newsockfd<0)
printerror("\n Error on accept");
printf("Enter the text\n");
scanf("%s",str);
i=0;
while(i<strlen(str))
{
memset(frame,0,20);
strncpy(frame,str+i,size);
printf("Transmitting frames");
len=strlen(frame);
for(j=0;j<len;j++)
{
printf("%d",i+j);
sprintf(temp,"%d",i+j);
strcat(frame,temp);
}
printf("\n\n");
write(newsockfd,frame,sizeof(frame));
read(newsockfd,ack,20);
sscanf(ack,"%d",&status);
if(status==-1)
printf("Transmission success\n");
else
{
printf("Recieved error in %d \n\n",status);
printf("Retransmitting the frame");
for(j=0;;)
{
frame[j]=str[j+status];
printf("%d",j+status);
j++;
if(((j+status) % 4)==0)
break;
}
printf("\n\n");
frame[j]='\0';
len=strlen(frame);
for(j=0;j<len;j++)
{sprintf(temp,"%d",j+status);
strcat(frame,temp);
}
write(newsockfd,frame,sizeof(frame));
}
i+=size;
}
write(newsockfd,"exit",sizeof("exit"));
printf("Exiting");
sleep(5);
close(newsockfd);
close(sockfd);
}

int printerror(char * msg)
{
perror(msg);
}
