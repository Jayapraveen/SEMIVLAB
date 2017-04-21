/*
ALGORITHM:
1.	Include the necessary header files.
2.	Create a socket using socket function with family AF_INET, type as SOCK_DGRAM.
3.	Declare structures arpreq ( as NULL structure, if required) and sockaddr_in.
4.	Initialize server address to 0 using the bzero function.
5.	Assign the sin_family to AF_INET and sin_addr using inet_aton().
6.	Using the object of arpreq structure assign the name of the Network Device to the data.
7.	Ping the required Client.
8.	Using the “arp –a” we get the ARP cache entry for the given IP address.
9.	Print the hardware address of the given IP address on the output console.
PROGRAM:
*/
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <netinet/in.h>
#include <net/if_arp.h>
int main(int argc,char *argv[])
{
  	char ipaddr[25],interfaceName[25],MAC[25];
	
	memset(ipaddr,0,sizeof(ipaddr));
	strcpy(ipaddr, argv[1]);
	memset(interfaceName, 0, sizeof ( interfaceName ) );
	strcpy(interfaceName,"p4p1");
	memset(MAC, 0, sizeof(MAC));
	getMAC(ipaddr, MAC, interfaceName);
	printf("IP address  %s is mapped to MAC address %s",ipaddr, MAC);
}
int getMAC( char *ipaddr, char *buf, char *interfaceName )
{
	int sockfd;
	unsigned char *ptr;
	struct arpreq arpreq;
	struct sockaddr_in *sin;
	struct sockaddr_storage ss;
	char addr[INET_ADDRSTRLEN+1];
	memset(addr,0,INET_ADDRSTRLEN +1);
	memset(&ss,0,sizeof(ss));
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd == -1)
	{
		printf ( "socket error" );
		return -1;
	}
	sin=(struct sockaddr_in *)&ss;
	sin->sin_family=AF_INET;
	if(inet_pton(AF_INET,ipaddr,&( sin->sin_addr))<= 0)
	{
		printf ( "inet_pton error" );
		return -1;
	}
	sin=(struct sockaddr_in *)&arpreq.arp_pa;
	memcpy(sin,&ss,sizeof(struct sockaddr_in));
	strcpy(arpreq.arp_dev,interfaceName);
	arpreq.arp_ha.sa_family=AF_UNSPEC;
	if(ioctl(sockfd,SIOCGARP,&arpreq)<0)
	{
		printf("ioctl SIOCGARP: " );
		return -1;
	}
	ptr=( unsigned char * )&arpreq.arp_ha.sa_data[0];
	sprintf(buf,"%02x:%02x:%02x:%02x:%02x:%02x   \n", *ptr,*(ptr+1),*(ptr+2),*(ptr+3),*(ptr+4),*(ptr+5));
	return 0;
}
