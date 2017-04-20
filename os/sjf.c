#include<stdio.h>
#include<string.h>
struct sjf{
int flag;
int bt,wt,tat,at;
char pname[3];
}f[10],temp,inter[10],final[10];

main()
{
int count=0;
 int i,j,n,m=0,k=0,p,q;
 int twt=0,ttat=0,totbt=0,tot;
 float awt,atat;
 printf("\n enter the no of processes: ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 { f[i].flag=0;
  printf("\n enter the process name: ");
  scanf("%s",f[i].pname);
  printf("\n enter the burst time: ");
  scanf("%d",&f[i].bt);
  printf("\n enter the arrival time: ");
  scanf("%d",&f[i].at);
 }
  for(i=0;i<n;i++)
  { if(f[i].at==0)
     count++;
   }
for(i=0;i<count;i++)
{ for(j=i+1;j<count;j++)
   { if(f[i].bt>f[j].bt)
     { temp=f[i];
       f[i]=f[j];
       f[j]=temp;
    }
 }
inter[m]=f[i];
m++;
}
if(count==n)
   {
    for(i=0;i<n;i++)
    { final[i]=inter[i];
      final[i].flag=1;
    }
   }
   else
   { final[k]=inter[0];
    f[0].flag=1;
     k++;
     tot=final[0].bt;
for(i=1;i<n;i++)
{     m=0;
       for(j=1;j<n;j++)
       {if(tot>=f[j].at&&f[j].flag==0)
	{ inter[m]=f[j];
	  m++;
	}
       }
       for(p=0;p<m;p++)
       {
	for(q=p+1;q<m;q++)
	{ if(inter[p].bt>inter[q].bt)
	  {
	   temp=inter[p];
	   inter[p]=inter[q];
	   inter[q]=temp;
	   }
	  }
   }
for(p=0;p<n;p++)
if(strcmp(f[p].pname,inter[0].pname)==0)
f[p].flag=1;
final[k]=inter[0];
tot+=final[k].bt;
k++;
}
     }
printf("\n order of execution: ");
for(i=0;i<k;i++)
{
    printf("%s ",final[i].pname);
}
final[0].wt=0;
  final[0].tat=final[0].bt;
  for(i=1;i<n;i++)
  {totbt+=final[i-1].bt;
   final[i].wt=totbt-final[i].at;
   final[i].tat=final[i].bt+final[i].wt;
   twt+=final[i].wt;
   ttat+=final[i].tat;
  }
  awt=(float)twt/n;
  ttat+=final[0].tat;
  atat=(float)ttat/n;
   printf("\npname\tbt\tat\twt\ttat\n");
  for(i=0;i<n;i++)
 { printf("%s\t%d\t%d\t%d\t%d\n",final[i].pname,final[i].bt,final[i].at,final[i].wt,final[i].tat);
 }
printf("\ntwt=%d\tttat=%d\nawt=%f\tatat=%f",twt,ttat,awt,atat);
 }
#OUTPUT:
#enter the no of processes: 6
#enter the process name: P1
#enter the burst time: 2
#enter the arrival time: 0
#enter the process name: P2
#enter the burst time: 2
#enter the arrival time: 1
#enter the process name: P3
#enter the burst time: 5
#enter the arrival time: 1
#enter the process name: P4
#enter the burst time: 2 
#enter the arrival time: 2
#enter the process name: P5
#enter the burst time: 3
#enter the arrival time: 2
#enter the process name: P6
#enter the burst time: 1
#enter the arrival time: 4 
#order of execution: P1 P2 P6 P4 P5 P3
#pname   bt    at      wt      tat
#P1           2       0       0       2
#P2           2       1       1       3
#P6           1       4       0       1
#P4           2       2       3       5
#P5           3       2       5       8
#P3           5       1       9       14
#twt=18  ttat=33
#awt=3.000000    atat=5.500000
