#include<stdio.h>
main()
{
        int nframes,len,i,j,k,flag,pf=0,frame[20],s[20];
        printf("enter the number of frames\n");
        scanf("%d",&nframes);
        for(i=1;i<=nframes;i++)
                frame[i]=0;
        fflush(stdin);
        printf("enter the length of the reference string\n");
        scanf("%d",&len);
        printf("enter the reference string\n");
        for(i=1;i<=len;i++)
                scanf("%d",&s[i]);
        j=1;
        for(i=1;i<=len;i++)
        {      flag=0;
                for(k=1;k<=nframes;k++)
                {
                        if(s[i]==frame[k])
                        {
                                flag=1;
                                break;}
                }
                if(flag!=1)   {
                        pf++;
                        frame[j++]=s[i];
                        if(j>nframes)
                                j=1;
                }
                for(k=1;k<=nframes;k++)
                        printf("%d\t",frame[k]);
                printf("\n");
        }
        printf("no. of page faults is %d",pf);
}


/*
OUTPUT:
[root@localhost student]# gcc fifo.c
[root@localhost student]# ./a.out
enter the number of frames
3
enter the length of the reference string
5
enter the reference string
1 2 3 1 3
1	0	0	
1	2	0	
1	2	3	
1	2	3	
1	2	3	
no. of page faults is 3


*/