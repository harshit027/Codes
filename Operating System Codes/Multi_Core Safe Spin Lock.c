#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<assert.h>

volatile int in_cs;
volatile int noOfThreads;
volatile int *count;


struct spin_lock_t
{
  int value;
};

typedef struct spin_lock_t spin_lock_t;

struct threadVar
{
  struct spin_lock_t *ts;
  long threadId;
} ;

typedef struct threadVar threadStruct;

static inline int atomic_cmpxchg (volatile int *ptr, int old, int new)
{
  int ret;
  asm volatile ("lock cmpxchgl %2,%1"
    : "=a" (ret), "+m" (*ptr)     
    : "r" (new), "0" (old)      
    : "memory");         
  return ret;                            
}

void spin_lock(volatile struct spin_lock_t *ts)
{
  do
 {
 } while(atomic_cmpxchg(&ts->value,0,1));

}

void spin_unlock(volatile struct spin_lock_t *ts)
{
  ts->value=0;
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
  
   spin_lock_t *s= malloc (sizeof(spin_lock_t *));
   s->value=0;
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

