#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
main()
{
 int child,id,n,i;
,0); 
 char *shmptr;
 int td;
 printf("\n enter the no of items: ");
 scanf("%d",&n);
 child=fork();
 if(!child) {
 id=shmget(2000,32,0666|IPC_CREAT);
 shmptr=shmat(id,0
 printf("\n child is adding item to buffer: ");
 for(i=0;i<n;i++) {
  shmptr[i]='A'+i;
  printf("\nadded item%d: %c",i+1,shmptr[i]);
 } exit(0);}
 else {
  wait(&td);
  id=shmget(2000,32,0666|IPC_CREAT);
  shmptr=shmat(id,0,0);
  printf("\n parent is now consuming:\n");
  for(i=0;i<n;i++)
  putchar(shmptr[i]);
  shmdt(NULL);
  shmctl(id,IPC_RMID,NULL);
}}
/*
OUTPUT:
enter the no of items: 3
 child is adding item to buffer:
added item1: A
added item2: B
added item3: C
 parent is now consuming:
ABC
*/