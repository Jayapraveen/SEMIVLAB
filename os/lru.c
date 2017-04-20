#include<stdio.h>
main()
{
        int nframes,len,t,u,min,rep,pos[20],i,j=1,k,m,flag,pf=0,frame[20],s[20];
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
        for(i=1;i<=len;i++)
        {
                flag=0;
                for(k=1;k<=nframes;k++)
                {
                        if(s[i]==frame[k])
                        {
                                flag=1;
                                break;
                        }
                }
                if(flag!=1)
                {
                        pf++;
                        if(j>nframes)
                        {
                                for(u=1;u<=nframes;u++)
                                {
                                        m=i-1;
                                        while(frame[u]!=s[m])
                                        {
                                                m--;
                                        }
                                        pos[frame[u]]=m;
                                }
                                min=pos[frame[1]];
                                rep=1;
                                for(u=2;u<=nframes;u++)
                                        if(pos[frame[u]]<min)
                                        {
                                                min=pos[frame[u]];
                                                rep=u;
                                        }
                                frame[rep]=s[i];
                        }
                        else
                                frame[j++]=s[i];
                }
                for(k=1;k<=nframes;k++)
                        printf("%d\t",frame[k]);
                printf("\n");
        }
        printf("no. of page faults is %d",pf);
}







*/

OUTPUT:

[root@localhost student]# ./a.out
enter the number of frames
3
enter the length of the reference string
5
enter the reference string
1 2 4 3 2        
1	0	0	
1	2	0	
1	2	4	
3	2	4	
3	2	4	
no. of page faults is 4
/*