#include<stdio.h>
#include<stdlib.h>
int main()
{
int alloc[20][20],max[20][20],avail[20],need[20][20];
int work[20]={0};
int newavail[20],req[20]={0},check=0,check2=0,cond=0,p;
int i=0,j=0,m=0,n=0,t=0,x=0,c[20]={0},k=0,count,count2,a[20],b;
int x2=0,c2[20];
printf("Enter the no of processes\n");
scanf("%d",&n);
printf("Enter the no of resources\n");
scanf("%d",&m);
printf("Enter the available resouces\n");
for(j=0;j<m;j++)
{
scanf("%d",&avail[j]);
work[j]=avail[j];
}
printf("Enter the allocated resources\n");
for(i=0;i<n;i++)
{ 
 for(j=0;j<m;j++)
 scanf("%d",&alloc[i][j]);
}
printf("Enter the maximum resources\n");
for(i=0;i<n;i++)
{
 for(j=0;j<m;j++)
 {
  printf("Enter the %d resources of %d max",j,i);
  scanf("%d",&max[i][j]);
  need[i][j]=max[i][j]-alloc[i][j];
 }
}
printf("\nNeed\n");
for(i=0;i<n;i++)
{
 for(j=0;j<m;j++)
 {
  printf("%2d",need[i][j]);
  printf("\n");
 }}
printf("Process executes in this order\n");
do
{
 for(i=0;i<n;i++)
 {
  count=0;
  if(c[i]!=i+1)
  {
   for(j=0;j<m;j++)
   {
     if(need[i][j]<=work[j])
     count=count+1;
   }
   if(count==m)
   {
    printf("p %d\t",i);
    c[i]=i+1;
    x=x+1;
    for(j=0;j<m;j++)
    work[j]=work[j]+alloc[i][j];
   }
  }
 }
check=check+1;
}while(x<n&&check<=n);
if(x==n)
 printf("system is in the safety\n");
else
 printf("System is not in the safety\n");
printf("Enter the process requesting additional resource\n");
scanf("%d",&p);
printf("Enter the request");
for(j=0;j<m;j++)
scanf("%d",&req[j]);
for(j=0;j<m;j++)
{
 if(req[j]<=avail[j]&&req[j]<=need[p][j])
 cond=cond+1;
}
if(cond==m)
{
 for(j=0;j<m;j++)
{
 alloc[p][j]=alloc[p][j]+req[j];
 avail[j]=avail[j]-req[j];
 need[p][j]=need[p][j]-req[j];
}}
else
{
printf("Request is not satisfied\n");
exit(0);
}
do
{
for(i=0;i<n;i++)
{
 count2=0;
 if(c2[i]!=i+1)
 {
  for(j=0;j<m;j++)
  {
   if(need[i][j]<=avail[j]);
   count2=count2+1;
  }
 if(count2==m)
 {
  printf("p%d\t",i);
  c2[i]=i+1;
  x2=x2+1;
  for(j=0;j<m;j++)
  avail[j]=avail[j]+alloc[i][j];
 }
}
}
check2=check2+1;
}while((x2<n)&&(check2<=n));
if(x2==n)
printf("\n System is in safestate we can grant the request");
else 
printf("\n System is in unsafe state we cannot grant the request");
return 0;
/*
OUTPUT:
ENTER NO OF PROCESS : 5
ENTER NO RES : 3
ENTER AVAILABLE RESOUREC 
3
3
2
ENTER THE ALLOCATED RESOURCES:
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
ENTER MAX RESOURCE:
7
4
3
1
2
2
5
0
0
0
1
1
4
3
1
PROCESS EXECUTES IN THIS ORDER
P1 P3 P4 P0 P2 SYSTEM IS IN SAFETY
ENTER THE PROCESS REQUESTING ADDITIONAL REOURCE
3
ENTER THGE REQUEST 3
*/