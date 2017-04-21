//server

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
int socketmain,socketclient,child,port=5122,len=81,n, expectedframe=0;
char late_ack;
struct sockaddr_in serv,clientaddr;
socklen_t clientlen;
if((socketmain=socket(AF_INET,SOCK_STREAM,0))<0)
 {
printf("\n server cannot open socket");
exit(0);
}
bzero(&serv,sizeof(serv));
serv.sin_family=AF_INET;
serv.sin_addr.s_addr=htonl(INADDR_ANY);
serv.sin_port=htons(atoi(argv[1]));
if((bind(socketmain,(struct sockaddr*)&serv,sizeof(serv)))<0)
{
printf("\n server bind failed");
exit(1);
}
listen(socketmain,5);
if((socketclient=accept(socketmain,(struct sockaddr*)&clientaddr,&clientlen))<0)
{
printf("\n client is bad");
exit(0);
}
char buf[len];
char str[10],frameno[]="012345678";
bzero(buf,len);
printf("FRAME NO        DATA");
while(expectedframe<=8)
{
n=read(socketclient,buf,2);
if(buf[0]==frameno[expectedframe])
{     printf("\n%c   %c", buf[0], buf[1]);
	if(buf[0]==late_ack){
		printf("Sending late ack\n");sleep(10);
}   
    write(socketclient,buf,2);
	expectedframe++;

}else
{if(buf[0]<frameno[expectedframe])
{  printf("\nReceived the frame %c already", buf[0]);
   write(socketclient,buf,2); } } } }

