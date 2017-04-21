/*
Server side
1.	Include the necessary header files.
2.	Create a socket using socket function with family AF_INET, type as SOCK_STREAM.
3.	Initialize server address to 0 using the bzero function.
4.	Assign the sin_family to AF_INET, sin_addr to INADDR_ANY, sin_port to dynamically assigned port number.
5.	Bind the local host address to socket using the bind function.
6.	Listen on the socket for connection request from the client.
7.	Accept connection request from the Client using accept function.
8.	Within an infinite loop, receive the file name from the Client.
9.	Open the file, read the file contents to a buffer and send the buffer to the Client.
*/
// Server Program: ftptcps.c
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
main()
{
    struct sockaddr_in clientaddr,serveraddr;
    int serversock,newserversock,clientsize,n,f,rc;
    char filename[100],filedata[300];
    fflush(stdin);
    serversock=socket(AF_INET,SOCK_STREAM,0);
    bzero((char*)&serveraddr,sizeof(serveraddr));
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=2000;
    serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    bind(serversock,(struct sockaddr*)&serveraddr,sizeof(serveraddr));    
    sizeof(serveraddr);
    listen(serversock,5);
    while(1)
    {
        clientsize=sizeof(clientaddr);
        newserversock=accept(serversock,(struct sockaddr*)&clientaddr,&clientsize);
        n=read(newserversock,filename,100);
        filename[n]=0;
        printf("\nThe requested file from the client is  %s.\n",filename);
        //write(1,filename,n);
        f=open(filename,O_RDWR);
        n=read(f,filedata,300);
        printf("\nThe contents of the file: \n\n");
        printf("%s",filedata);
        write(newserversock,filedata,n);
    }
    close(serversock);
    close(newserversock);
}
