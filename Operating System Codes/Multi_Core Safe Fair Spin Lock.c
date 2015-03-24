#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<assert.h>

volatile int in_cs;
volatile int noOfThreads;
volatile int *count;


static inline int atomic_xadd (volatile int *ptr)
{
  register int val __asm__("eax") = 1;
  asm volatile ("lock xaddl %0,%1"
  : "+r" (val)
  : "m" (*ptr)
  : "memory"
  );  
  return val;
}
struct fair_spin_lock_t
{
  volatile int token;
  volatile int user;
};

typedef struct fair_spin_lock_t fair_spin_lock_t;

struct threadVar
{
  struct fair_spin_lock_t *ts;
  long threadId;
} ;

typedef struct threadVar threadStruct;


void spin_lock(volatile fair_spin_lock_t *ts)
{
  int  currentUser = atomic_xadd(&ts->user);
  while (ts->token != currentUser)
  {}     

}

void spin_unlock(volatile fair_spin_lock_t *ts)
{
 asm volatile("": : :"memory");
 ts->token++;
}
 

void* ThreadStart(void* threadNo)
{
  struct threadVar *tv= (struct threadVar*) threadNo;
  while(1)
  {
    spin_lock(tv->ts);
    count[tv->threadId]=count[tv->threadId]+1;
    assert (in_cs==0);
    in_cs++;
    assert (in_cs==1);
    in_cs++;
    assert (in_cs==2);
    in_cs++;
    assert (in_cs==3);
    in_cs=0;
    spin_unlock(tv->ts);
  } 
}
int main(int argc, char*  argv[])
{
  
   if(argc!=3)
   {
      printf("Invalid number of arguments.");
      return -1;
   }
   
   printf("%s %s", argv[1], argv[2]);
   
   int duration;
   noOfThreads=atoi(argv[1]);
   duration=atoi(argv[2]);
   long i;
   int flag;
 


   fair_spin_lock_t *s= malloc (sizeof(fair_spin_lock_t *));
   s->token=0;
   s->user=0;
   count=(int *) malloc (sizeof(int) * noOfThreads);
   
  
   pthread_t *threadArr;
   threadArr=(pthread_t *) malloc (sizeof(pthread_t) * noOfThreads);
   for(i=0;i<noOfThreads;i++)
   {
     count[i]=0;
   }
   
  
   for(i=0;i<noOfThreads;i++)
   {
      threadStruct *tv=malloc(sizeof(threadStruct *));
      tv->threadId=i;
      tv->ts=s;
      flag=pthread_create(&threadArr[i], NULL, ThreadStart,(void *) tv);
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

