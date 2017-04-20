#include<stdio.h>
struct fcfs
{
char name[5];
int at,wt,bt,tat;
}f1[10];
main()
{
int n;
int totbt=0;
printf(“\nenter the no. of processes:”);
scanf(“%d”,&n);
for(i=1;i<=n;i++)
{
printf(“\nprocess name?”);
scanf(“%s”,f1[i].name);
f1[i].at=f1[i].wt=0;
printf(“\nburst time?”);
scanf(“%d”,&f1[i].bt);
printf(“\narrival time?”);
scanf(“%d”,&f1[i].at);
}
f1[1].wt=0;
f1[1].tat=f1[1].bt+f1[1].wt;
f1[1].at=0;
for(i=1;i<=n;i++)
{totbt+=f[i-1].wt;
f1[i].wt=totbt-f[i].at;
f1[i].tat=f1[i].wt+f1[i].bt;
}
for(i=1;i<=n;i++)
 f1[i].wt=f1[i].wt-f1[i].at;
 printf(“\npname\tbt\tat\twt\ttat\n”);
 for(i=1;i<=n;i++)
{
 printf(“%s\t%d\t%d\t%d\t%d\n”,f1[i].name,f1[i].bt,f1[i].at,f1[i].wt,f1[i].tat);
}
}
#Output:
#enter the no. of processes:4
#process name?p1
#burst time?10
#arrival time?0 
#process name?p2
#burst time?4
#arrival time?1
#process name?p3
#burst time?2
#arrival time?2
#process name?p4
#burst time?7
#arrival time?2
#
#pname   bt      at      wt      tat
#p1           10      0       0        10
#p2           4        1       9        14
#p3           2        2      12       16
#p4           7        2      14       23
