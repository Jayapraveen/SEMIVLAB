 #include<stdio.h>
struct prior{
int pri;
int count;
int bt,wt,tat,at;
char pname[3];
}f[10],temp;
main()
{
 int i,j,n;
 int twt=0,ttat=0,totbt=0;
 float awt,atat;
 printf("\n enter the no of processes: ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 { 	f[i].at=0;
    	f[i].count=i+1 ;
     	printf("\n enter the process name: ");
     	scanf("%s",f[i].pname);
  	printf("\n enter the burst time: ");
  	scanf("%d",&f[i].bt);
  	printf("\n enter the priority ");
  	scanf("%d",&f[i].pri);
 }
 for(i=0;i<n;i++)
 {
  for(j=i+1;j<n;j++)
  {
   if(f[i].pri>f[j].pri)
   { temp=f[i];
     f[i]=f[j];
     f[j]=temp;
   }
   if(f[i].pri==f[j].pri)
   { if(f[i].count>f[j].count)
     {  temp=f[i];
	f[i]=f[j];
	f[j]=temp;
     }
   }
  }
  }
  printf("\n order of execution: ");
  for(i=0;i<n;i++)
  printf("%s ",f[i].pname);
  f[0].wt=0;
  f[0].tat=f[0].bt;
  for(i=1;i<n;i++)
  {totbt+=f[i-1].bt;
   f[i].wt=totbt-f[i].at;
   f[i].tat=f[i].bt+f[i].wt;
   twt+=f[i].wt;
   ttat+=f[i].tat;
  }
  awt=(float)twt/n;
  ttat+=f[0].tat;
  atat=(float)ttat/n;
   printf("\npname\tbt\tat\tprior\twt\ttat\n");
  for(i=0;i<n;i++)
 {  
    printf("%s\t%d\t%d\t%d\t%d\t%d\n",f[i].pname,f[i].bt,f[i].at,f[i].pri,f[i].wt,   
              f[i].tat);
 }
 printf("\ntwt=%d\tttat=%d\nawt=%f\tatat=%f",twt,ttat,awt,atat);
 }
/*OUTPUT:	
enter the no of processes:3
enter the process name:P1 
enter the burst time: 10
enter the priority 3
enter the process name: P2
enter the burst time: 2
enter the priority 1
enter the process name: P3
enter the burst time: 4
enter the priority 3
order of execution: P2 P1 P3
pname   bt     at   prior   wt      tat
P2           2       0       1       0       2
P1          10      0       3       2       12
P3           4       0       3       12     16
twt=14  ttat=30
awt=4.666667    atat=10.000000
*/