/*
ALGORITHM:
1.	Start the program
2.	Create the parameters and call ping_construct() to check the queue is empty or not
3.	Initialize the address structure using ping_host_addr() and print the success message.
4.	Call ping_send() to check the connection then if  return the value is negative,display error message.
5.	Else get the information using ping_iterator_get_info(),Display the hostname and latency. 
6.	Stop the program.
PROGRAM
*/
#include <stdlib.h>
#include <stdio.h>
#include <oping.h>
int main(int argc, char **argv)
{
pingobj_t *ping;
pingobj_iter_t *iter;
if ((ping = ping_construct()) == NULL)
{
fprintf(stderr, "ping_construct failed\n");
return (-1);
}
printf("ping_construct() success\n");
if (ping_host_add(ping, argv[1]) < 0)
{
const char * errmsg = ping_get_error(ping);
fprintf(stderr, "ping_host_add(argv[1]) failed. %s\n", errmsg);
return (-1);
}
printf("ping_host_add() success\n");
while (1)
{
if (ping_send(ping) < 0)
{
fprintf(stderr, "ping_send failed\n");
return(-1);
}
printf("ping_send() success\n");
for (iter = ping_iterator_get(ping); iter != NULL; iter=ping_iterator_next(iter))
{
char hostname[100];
double latency;
unsigned int len;
printf("ping_iterator_get() success\n");
len = 100;
ping_iterator_get_info(iter, PING_INFO_HOSTNAME, hostname, &len);
len = sizeof(double);
ping_iterator_get_info(iter, PING_INFO_LATENCY, &latency, &len);
printf("hostname = %s, latency = %f\n", hostname, latency);
}
sleep(1);
}
printf("exiting...\n");
return (0);
}
/*
OUTPUT:
[root@localhost  ~]# ./a.out 172.16.8.40
IP address 172.16.8.40 is mapped to MAC address 00:02:b6:42:88:1c










RESULT: Thus a C program to implement PING is executed successfully.
*/