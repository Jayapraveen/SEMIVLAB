//Client

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
int main(int argc,char **argv)
{
int sockfd,n,port=5222, sentframe=0;
struct sockaddr_in serv;
char buf[100],msg[100];
if(argc!=3)
{
printf("invalid format");
exit(0);
}
if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
{
printf("\n socket cannot be opened");
exit(0);
}
bzero(&serv,sizeof(serv));
serv.sin_family=AF_INET;
serv.sin_port=htons(atoi(argv[2]));
if(connect(sockfd,(struct sockaddr*)&serv,sizeof(serv))<0)
{
printf("\n connection failed");
exit(0);
}
printf("\n connected");
char error='\0';
char framelost='\0';
char acklost='\0';
char timeframe='\0';
char DATA[]="ABCDEFGHI";
char frameno[]="012345678";
int flag1=1, flag2=1;
printf(" Like to introduce error y or n");
scanf("%c",&error);
if(error=='y')
{
printf("\nEnter the ack frame no assumed to be lost\n ");
scanf(" %c",&acklost);
printf("\nEnter the frame no assumed to be lost\n ");
scanf(" %c",&framelost);
}
printf("FRAME NO        DATA\n");
while(sentframe<=8)
{
buf[0]=frameno[sentframe];
buf[1]=DATA[sentframe];
printf("%c       %c\n",buf[0], buf[1]);
if(framelost==buf[0] && error=='y' && flag1==1)
{
	printf("Time out due to frame lost : Ack not received.....Resending the same frame\n");
		flag1=0;sleep(4);continue;}
else{
write(sockfd,buf,2);
}
sleep(4);
if((n=read(sockfd,buf,2))!=0)
{	
	if(acklost==buf[0] && error=='y' && flag2==1)
	{        printf("Time out due to ack lost : Ack not received.....Resending the same frame\n");
		flag2=0;}
	else
	if(buf[0]==frameno[sentframe])
		sentframe++; }
else
{ printf("Time out....");} } }



