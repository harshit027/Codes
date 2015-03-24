#include<pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<unistd.h> 
#define SEED 35791246

volatile int noOfThreads;
volatile double noOfIterations;
volatile double  count;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void * CalculatePi(void *threadId)
{
  int id=(intptr_t) threadId; 
  id++; 
  int err;
  double  x,y,z;
  srand(SEED);
  while(1)
  {
    err=pthread_mutex_lock(&mutex);
    if(err!=0)
    {
    	printf("Error in Mutex Lock");
    	exit(0);
	}
    noOfIterations++;
    x = (double)rand()/RAND_MAX;
    y = (double)rand()/RAND_MAX;
    z = x*x+y*y;
    if (z<=1) 
     count++;
    err=pthread_mutex_unlock(&mutex);
    if(err!=0)
    {
    	printf("Error in Mutex Lock");
    	exit(0);
    }
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
   
   noOfIterations=0;
   count=0; 
   int duration;
   noOfThreads=atoi(argv[1]);
   duration=atoi(argv[2]);
   long i;
   int flag;
   double pi; 
   pi=0;
     
   pthread_t *threadArr;
   threadArr=(pthread_t *) malloc (sizeof(pthread_t) * noOfThreads);
  
   
   for(i=0;i<noOfThreads;i++)
   {

      flag=pthread_create(&threadArr[i], NULL, CalculatePi,(void *)  i);
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
  
  printf("\n No of Iterations = %f, Global Count = %f",noOfIterations,count);
  
  pi=count/noOfIterations*4;
  printf("\n\nPi = %f",pi);
   
   return 0;
}                                                                     
