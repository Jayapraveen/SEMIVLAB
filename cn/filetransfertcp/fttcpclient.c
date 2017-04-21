/*
Client side
1.	Include the necessary header files.
2.	Create a socket using socket function with family AF_INET, type as SOCK_STREAM.
3.	Initialize server address to 0 using the bzero function.
4.	Assign the sin_family to AF_INET.
5.	Get the server IP address and the Port number from the console.
6.	Using gethostbyname function assign it to a hostent structure, and assign it to sin_addr of the server address structure.
7.	Within an infinite loop, send the name of the file to be viewed to the Server.
8.	Receive the file contents, store it in a file and print it on the console.
*/
// Client Program: ftptcpc.c
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
#include<netdb.h>
#include<stdlib.h>
main()
{
    struct sockaddr_in serveraddr;
    int clientsock,n,rdret,length;
    char filename[20],filedata[300];
    bzero((char*)&serveraddr,sizeof(serveraddr));
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=2000;
    serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    clientsock=socket(AF_INET,SOCK_STREAM,0);
    if(connect(clientsock,(struct sockaddr*)&serveraddr,sizeof(serveraddr))<0)
    {
        printf("\nError:Cannot connect...");
        exit(0);
    }
    printf("Enter the name of the file : ");
    scanf("%s",filename);
    length=strlen(filename);
    write(clientsock,filename,length);
    rdret=read(clientsock,filedata,300);
    printf("\nThe contents of the file: \n\n");
    printf("%s",filedata);
    close(clientsock);
}
