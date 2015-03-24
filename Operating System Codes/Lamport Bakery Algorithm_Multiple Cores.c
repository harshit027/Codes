#include<assert.h>
#include<unistd.h>
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>


volatile int in_cs;
volatile int noOfThreads;
volatile int *entering;
volatile int *turn;
volatile int *count;

void mfence (void) {
  asm volatile ("mfence" : : : "memory");
}
int max()
{
   int i=0,max=0;
   for(i=0;i<noOfThreads;i++)
   {
     if(max<turn[i])
     max=turn[i];
   }
   return max;
}

void acquire(int threadNo)
{
   int j;
   entering[threadNo]=1;
   mfence();
   //mfence() used
   turn[threadNo]=1+max(turn,noOfThreads);
   entering[threadNo]=0;
   mfence();
   //*turn and *entering arrays are used to preserve the order of the threads, keeping mfence() at this point will preserve
   //the order of load and store instructions and hence preserve the order of the threads.
   //Additional mfence() are not necessary as this is the only place where multiple threads are manipulating the data structures which 
   //are used by Bakery algorithm for preserving the order.
   for(j=0;j<noOfThreads;j++)
   {
      while(entering[j])
      {} 
      while((turn[j]!=0) && ((turn[j]<turn[threadNo])|| ((turn[j]==turn[threadNo])&&(j<threadNo))))
      {}
   }
   
}

void release(int threadNo)
{
   turn[threadNo]=0;
}

void* ThreadStart(void* threadNo)
{
  int id=(intptr_t) threadNo;
  //printf("\nThread No : %d", id);
  while(1)
  {
    acquire(id);
    count[id]=count[id]+1;    
    assert (in_cs==0);
    in_cs++;  
    assert (in_cs==1);
    in_cs++;    
    assert (in_cs==2);
    in_cs++;    
    assert (in_cs==3);
    in_cs=0;
    release(id);
  } 
}
int main(int argc, char*  argv[])
{
 // printf("check-1"); 
   if(argc!=3)
   {
      printf("Invalid number of arguments.");
      return -1;
   }
   
   printf("%s %s", argv[1], argv[2]);
   
  // printf("check0");
   int duration;
   noOfThreads=atoi(argv[1]);
   duration=atoi(argv[2]);
   long i;
   int flag;
  // printf("check1");

   
   entering=(int *) malloc (sizeof(int)* noOfThreads);
   turn=(int *) malloc (sizeof(int) * noOfThreads);
   count=(int *) malloc (sizeof(int) * noOfThreads);
   // printf("check2");   
  
   pthread_t *threadArr;
   threadArr=(pthread_t *) malloc (sizeof(pthread_t) * noOfThreads);
   for(i=0;i<noOfThreads;i++)
   {
     entering[i]=0;
     turn[i]=0;
     count[i]=0;
   }
   
   for(i=0;i<noOfThreads;i++)
   {

      flag=pthread_create(&threadArr[i], NULL, ThreadStart,(void *)  i);
      if(flag)
      {
        printf("Error creating a thread.");
        return -1;
      }
   }
   
  flag=usleep(duration * 1000000);
  if(flag)
  {
    printf("\n Failed in usleep");
   return -1;
  }
  for(i=0;i<noOfThreads;i++)
  {
    printf("\n Thread No = %ld : Count = %d",i,count[i]);
  }
   
   return 0;
}

