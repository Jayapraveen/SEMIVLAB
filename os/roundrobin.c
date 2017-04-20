#include<stdio.h>
struct round
{
 int flag;
 int nts,bt,at,wt,tat;
 char pname[3];
 int st,et;
 int tbt;
}f[10],rd[15];
main()
{ int tempo;
 int ts;
 int max,i,j,n,k=0,m;
 int twt=0,ttat=0;
 float awt,atat;
 printf("\n enter the no of processes: ");
 scanf("%d",&n);
 printf("\n enter the time slice: ");
 scanf("%d",&ts);
 for(i=0;i<n;i++)
{
  f[i].at=0;
  f[i].flag=0;
   printf("\n enter the process name: ");
  scanf("%s",f[i].pname);
  printf("\n enter the burst time: ");
  scanf("%d",&f[i].bt);
  f[i].tbt=f[i].bt;
  f[i].nts=f[i].bt/ts;
  if(f[i].bt%ts!=0)
  f[i].nts=f[i].nts+1;
}
max=f[0].nts;
for(i=1;i<n;i++)
if(max<f[i].nts)
max=f[i].nts;
printf("\n max=%d",max);
for(j=0;j<max;j++)
{ for(i=0;i<n;i++)
  {
   if(f[i].nts>0&&f[i].flag==0)
    {
       if(f[i].tbt>ts)
       {
        f[i].tbt-=ts;
        rd[k]=f[i];
        rd[k].bt=ts;
          f[i].nts--;
        k++;
       }
       else
       {
         rd[k]=f[i];
         rd[k].bt=f[i].tbt;
         k++;
         f[i].nts--;
       }
     }
   else if(f[i].nts==0)
   f[i].flag=1;
   }
}
rd[0].st=0;
rd[0].et=rd[0].bt;
tempo=rd[0].bt;
for(i=1;i<k;i++)
{
 rd[i].st=tempo;
 tempo+=rd[i].bt;
 rd[i].et=tempo;
}
printf("\n READY QUEUE: ");
printf("\nPNAME\tST\tET\n");
for(i=0;i<k;i++)
printf("%s\t%d\t%d\n",rd[i].pname,rd[i].st,rd[i].et);
for(i=0;i<n;i++)
{
 f[i].wt=rd[i].st;
m=rd[i].et;
for(j=i+1;j<k;j++)
{
 if(strcmp(f[i].pname,rd[j].pname)==0)
 {
   f[i].wt+=(rd[j].st-m);
    m=rd[j].et;
}
}
twt+=f[i].wt;
}
awt=(float)twt/n;
printf("\n pname\tbt\twt\n");
for(i=0;i<n;i++)
printf("%s\t%d\t%d\n",f[i].pname,f[i].bt,f[i].wt);
printf("twt=%d\tawt=%f",twt,awt);
}





#OUTPUT:
#enter the no of processes: 3
#enter the time slice: 3
#enter the process name: p1
#enter the burst time: 11
#enter the process name: p2
#enter the burst time: 4
#enter the process name: p3
#enter the burst time: 3
#max=4
#READY QUEUE:
#PNAME   ST      ET
#p1      0       3
#p2      3       6
#p3      6       9
#p1      9       12
#p2      12      13
#p1      13      16
#p1      16      18
#
#pname  bt      wt
#p1        11      7
#p2         4       9
#p3         3       6
#twt=22  awt=7.333333
