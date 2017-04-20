#include<stdio.h>
int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n,r;
void input();
void show();
void cal();
int main()
{
int i,j;
printf("\n********deadlock detection algorithm********\n");
input();
show();
cal();
return 0;
}
void input()
{
int i,j;
printf("\nenter the no. of processors is:\n");
scanf("%d",&n);
printf("\nenter the no. of resource instances:\n");
scanf("%d",&r);
printf("\nenter the max:\n");
for(i=0;i<n;i++)
{
for(j=0;j<r;j++)
scanf("%d",&max[i][j]);
}
printf("\nenter the allocated resources:\n");
for(i=0;i<n;i++)
{
for(j=0;j<r;j++)
scanf("%d",&alloc[i][j]);
}
printf("\nenter the available resources:\n");
for(j=0;j<r;j++)
scanf("%d",&avail[j]);
}
void show()
{
int i,j;
printf("process\tallocation\tmax\tavailable\t");
for(i=0;i<n;i++)
{
printf("\n   p%d\t",i+1);
for(j=0;j<r;j++)
printf("  %d",alloc[i][j]);
printf("\t");
for(j=0;j<r;j++)
printf("%d",max[i][j]);
printf("\t");
if(i==0)
{
for(j=0;j<r;j++)
printf("%d",avail[j]);
}
}
}
void cal()
{
int finish[100],temp,need[100][100],flag=1,k,cl=0;
int dead[100],safe[100],j,i;
for(i=0;i<n;i++)
finish[i]=0;
for(i=0;i<n;i++)
{
for(j=0;j<r;j++)
need[i][j]=max[i][j]-alloc[i][j];
}
while(flag)
{
flag=0;
for(i=0;i<n;i++)
{
int c=0;
for(j=0;j<r;j++)
{
if((finish[i]==0)&&(need[i][j]<=avail[j]))
{
c++;
if(c==r)
{
for(k=0;k<r;k++)
{
avail[k]+=alloc[i][j];
finish[i]=1;
flag=1;
}
printf("\np%d\n",i);
if(finish[i]==1)
i=n;
}}}}}
j=0;
flag=0;
for(i=0;i<n;i++)
{
if(finish[i]==0)
{
dead[j]=i;
j++;
flag=1;
}}
if(flag==1)
{
printf("\n\nsystem is in dead lock and the dead lock process are\n");
for(i=0;i<n;i++)
printf("p%d\t",dead[i]+1);
printf("\n");
}
else
printf("\n no deadlock occur\n");
}
/*
output:
enter the no of proces:
3

enter the no of resource instances:
3

enter the max:
3 6 8
4 3 3
3 4 4

enter the allocated resources:
3 3 3
2 0 3
1 2 4

enter te available resorces:
1 2 0
process allocation max available
p1 3 3 3           368  120
p2 2 0 3		   433
p3 1 2 4			344
system is in deadlock and the deadlock process are 
p1  p2  p3
*/