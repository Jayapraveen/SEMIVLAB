#include<stdio.h>
#include<conio.h>
main()
{
 int n,i,j,b[20],sb[20],t[20],x,c[20][20];
 clrscr();
 printf("Enter no.of files:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
	printf("Enter no. of blocks occupied by file%d",i+1);
	scanf("%d",&b[i]);
	printf("Enter the starting block of file%d",i+1);
	scanf("%d",&sb[i]);
	t[i]=sb[i];
	for(j=0;j<b[i];j++)
		c[i][j]=sb[i]++;
	}
 printf("Filename\tStart block\tlength\n");
 for(i=0;i<n;i++)
	printf("%d\t  %d \t%d\n",i+1,t[i],b[i]);
 printf("Enter file name:");
 scanf("%d",&x);
 printf("File name is:%d",x);
 printf("length is:%d",b[x-1]);
 printf("blocks occupied:");
 for(i=0;i<b[x-1];i++)
	printf("%4d",c[x-1][i]);
 getch();
}
/*Output:
Enter no.of files: 2                                                             
Enter no. of blocks occupied by file1 4                                          
Enter the starting block of file1 2                                             
 Enter no. of blocks occupied by file2 10                                         
Enter the starting block of file2 5                                              
Filename        Start block     length                                         
 1                         2                    4                                                               
2                          5                    10                                                              
Enter file name: rajesh                                                         
 File name is:12803 length is:0blocks occupied   
*/