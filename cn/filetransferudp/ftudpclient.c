/*
Client side
1.	Include the necessary header files.
2.	Create a socket using socket function with family AF_INET, type as SOCK_ DGRAM.
3.	Initialize server address to 0 using the bzero function.
4.	Assign the sin_family to AF_INET.
5.	Get the server IP address and the Port number from the console.
6.	Using gethostbyname function assign it to a hostent structure, and assign it to sin_addr of the server address structure.
7.	Within an infinite loop, send the name of the file to be viewed to the Server.
8.	Receive the file contents, store it in a file and print it on the console.
*/
// FTP Client Program: ftpudpc.c
#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<stdlib.h>
main()
{
    struct sockaddr_in server,client;
    int s,n,ret;size_t fp;
    char filename[20],downloaded[10],filedata[100],c[25];
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    s=socket(AF_INET,SOCK_DGRAM,0);
    server.sin_family=AF_INET;
    server.sin_port=2000;
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    n=sizeof(server);
    printf("Enter the name of the file: ");
    scanf("%s",filename);
    printf("\nEnter a name to save: ");
    scanf("%s",downloaded);
    printf("\nDownloading...\n");
    sendto(s,filename,sizeof(filename),0,(struct sockaddr *)&server,n);
    fp = open(downloaded, O_WRONLY | O_CREAT | O_TRUNC, mode);
    if(fp==-1)
    {
        printf("\nError...");
        exit(0);
    }
    recvfrom(s,filedata,sizeof(filedata),0,NULL,NULL);
    printf("\nProcessing Contents...\n");
    while(1)
    {
        if(strcmp(filedata,"end")==0)
            break;
    printf("%s",filedata);
        ret=write(fp,filedata,strlen(filedata));
        bzero(filedata,100);
        recvfrom(s,filedata,sizeof(filedata),0,NULL,NULL);
    }
    printf("\nFile downloaded successfully...\n");
}
