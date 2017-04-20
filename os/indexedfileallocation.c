#include<stdio.h>
#include<conio.h>
main()
{
 int n,m[20],i,j,sb[20],s[20],b[20][20],x;
 clrscr();
 printf("Enter no. of files:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {	printf("Enter starting block and size of file%d:",i+1);
	scanf("%d%d",&sb[i],&s[i]);
	printf("Enter blocks occupied by file%d:",i+1);
	scanf("%d",&m[i]);
	printf("enter blocks of file%d:",i+1);
	for(j=0;j<m[i];j++)
		scanf("%d",&b[i][j]);
 } printf("\nFile\t index\tlength\n");
 for(i=0;i<n;i++)
 {
	printf("%d\t%d\t%d\n",i+1,sb[i],m[i]);
 }printf("\nEnter file name:");
 scanf("%d",&x);
 printf("file name is:%d\n",x);
 i=x-1;
 printf("Index is:%d",sb[i]);
 printf("Block occupied are:");
 for(j=0;j<m[i];j++)
	printf("%3d",b[i][j]);
 getch();
}


/*Output:
Enter no. of files:2                                                           
 Enter starting block and size of file1: 2   5                                      
Enter blocks occupied by file1:10                                               
enter blocks of file1:3                                                         
2  5   4  6  7   2   6  4  7                                                                               
Enter starting block and size of file2: 3   4                                      
Enter blocks occupied by file2:5                                                
enter blocks of file2: 2  3   4  5   6                                                                                                                                                               File     index  length                                                         
 1       2       10                                                              
2       3       5                                                                                                                                               
Enter file name: venkat                                                          
file name is:12803                                                              
*/