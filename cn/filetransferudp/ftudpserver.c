/*
Server side
1.	Include the necessary header files.
2.	Create a socket using socket function with family AF_INET, type as SOCK_DGRAM.
3.	Initialize server address to 0 using the bzero function.
4.	Assign the sin_family to AF_INET, sin_addr to INADDR_ANY, sin_port to dynamically assigned port number.
5.	Bind the local host address to socket using the bind function.
6.	Within an infinite loop, receive the file name from the Client.
7.	Open the file, read the file contents to a buffer and send the buffer to the Client.
*/
// FTP Server Program: ftpudps.c
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
main()
{
    struct sockaddr_in server,client;
    int serversock,n,fp,end;
    char filename[20],buffer[100];
    serversock=socket(AF_INET,SOCK_DGRAM,0);
    server.sin_family=AF_INET;
    server.sin_port=2000;
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    bind(serversock,(struct sockaddr *)&server,sizeof(server));
    n=sizeof(client);
    recvfrom(serversock,filename,sizeof(filename), 0,(struct sockaddr *)&client,&n);
    fp=open(filename,O_RDONLY);
    while(1)
    {
        end=read(fp,buffer,sizeof(buffer));
        if(end==0)
            break;
        sendto(serversock,buffer,sizeof(buffer),0,(struct sockaddr *)&client,n);
        bzero(buffer,100);
    }
    strcpy(buffer,"end");
    sendto(serversock,buffer,sizeof(buffer),0,(struct sockaddr *)&client,n);
}

