#include<assert.h>
#include<unistd.h>
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

volatile int cat_plays,dog_plays,bird_plays,cats,dogs,birds,n_cats,n_dogs,n_birds;
volatile int err;
struct monitor
{
  //int playground;
  pthread_mutex_t mutex;
  pthread_cond_t is_occupied_cat;
  pthread_cond_t is_occupied_dog;
  pthread_cond_t is_occupied_bird;
};

typedef struct monitor MONITOR;

MONITOR *monitorObj;

  void cat_enter(void)
  {
    
    err=pthread_mutex_lock(&monitorObj->mutex);
    if(err)
    printf("Failed in mutex lock");
    while(dogs>0 || birds>0)
    {
      err=pthread_cond_wait(&monitorObj->is_occupied_cat, &monitorObj->mutex);
      if(err)
      printf("Failed in cond wait");
    };
    cats++;
    err=pthread_mutex_unlock(&monitorObj->mutex);
    if(err)
    printf("Failed in mutex unlock");
  }
  void cat_exit(void)
  {
    err=pthread_mutex_lock(&monitorObj->mutex);
    if(err)
    printf("Failed in mutex lock");
    err=pthread_cond_signal(&monitorObj->is_occupied_cat);
    if(err)
    printf("Failed in cond signal");
    cats--;
    err=pthread_mutex_unlock(&monitorObj->mutex);
    if(err)
    printf("Failed in mutex unlock");

  }
  void dog_enter(void)
  {
   
    pthread_mutex_lock(&monitorObj->mutex);
    while(cats>0)
    {
      pthread_cond_wait(&monitorObj->is_occupied_dog, &monitorObj->mutex);
    };
    dogs++;
    pthread_mutex_unlock(&monitorObj->mutex);
  }
  void dog_exit(void)
  {
   
    pthread_mutex_lock(&monitorObj->mutex);
    pthread_cond_signal(&monitorObj->is_occupied_dog);
    dogs--;
    pthread_mutex_unlock(&monitorObj->mutex);
  }
  void bird_enter(void)
  {
   
    pthread_mutex_lock(&monitorObj->mutex);
    while(cats>0)
    {
      pthread_cond_wait(&monitorObj->is_occupied_bird, &monitorObj->mutex);
    }
    birds++;
    pthread_mutex_unlock(&monitorObj->mutex);
  }
  void bird_exit(void)
  {
   
    pthread_mutex_lock(&monitorObj->mutex);
    pthread_cond_signal(&monitorObj->is_occupied_bird);
    birds--;
    pthread_mutex_unlock(&monitorObj->mutex);
  }
 

void play(void) {
 
  for (int i=0; i<10; i++) {
    assert(cats >= 0 && cats <= n_cats);
    assert(dogs >= 0 && dogs <= n_dogs);
    assert(birds >= 0 && birds <= n_birds);
    assert(cats == 0 || dogs == 0);
    assert(cats == 0 || birds == 0);
   }
}

void * catThread(void * threadId)
{
  while(1)
  {
  cat_enter();
  cat_plays=cat_plays+1;
  play();
  cat_exit();
  }
  exit(0);
}

void * dogThread(void * threadId)
{
  while(1)
  {
  dog_enter();
  dog_plays=dog_plays+1;
  play();
  dog_exit();
  }
  exit(0);
}

void * birdThread(void * threadId)
{
  while(1)
  {
  bird_enter();
  bird_plays=bird_plays+1;
  play();
  bird_exit();
  }
  exit(0);
}


int main(int argc, char* argv[])
{
  if(argc!=4)
   {
      printf("Invalid number of arguments.");
      return -1;
   }
   
   printf("Cats = %s, Dogs =  %s, Birds =  %s", argv[1], argv[2], argv[3]);
   
   n_cats=atoi(argv[1]);
   n_dogs=atoi(argv[2]);
   n_birds=atoi(argv[3]);
   int flag;
   long i;
   dog_plays=0;
   cat_plays=0;
   bird_plays=0;
   cats=0;
   birds=0;
   dogs=0;
   monitorObj= (MONITOR *) malloc(sizeof(MONITOR));
   pthread_mutex_init(&monitorObj->mutex, NULL);
   pthread_cond_init(&monitorObj->is_occupied_cat, NULL);
   pthread_cond_init(&monitorObj->is_occupied_dog, NULL);
   pthread_cond_init(&monitorObj->is_occupied_bird, NULL);
   
   pthread_t *catThreads, *dogThreads, *birdThreads;
   catThreads=(pthread_t*) malloc(sizeof(pthread_t) * n_cats);
   dogThreads=(pthread_t*) malloc(sizeof(pthread_t) * n_dogs);
   birdThreads=(pthread_t*) malloc(sizeof(pthread_t) * n_birds);
   
   for(i=0;i<n_cats;i++)
   {
      flag=pthread_create(&catThreads[i], NULL, catThread,(void *)i);
      if(flag)
      {
        printf("Error creating a thread.");
        return -1;
      }
   }
   for(i=0;i<n_dogs;i++)
   {
      flag=pthread_create(&dogThreads[i], NULL, dogThread,(void *)i);
      if(flag)
      {
        printf("Error creating a thread.");
        return -1;
      }
   }
   for(i=0;i<n_birds;i++)
   {

      flag=pthread_create(&birdThreads[i], NULL, birdThread,(void *)i);
      if(flag)
      {
        printf("Error creating a thread.");
        return -1;
      }
   }
  
  flag=usleep(1000000);
  if(flag)
  {
    printf("\n Failed in usleep");
   return -1;
  }

  printf("\nCat Plays = %d\nDog Plays = %d\nBird Plays = %d",cat_plays,dog_plays,bird_plays);
  pthread_mutex_destroy(&monitorObj->mutex);
  pthread_cond_destroy(&monitorObj->is_occupied_cat);
  pthread_cond_destroy(&monitorObj->is_occupied_dog);
  pthread_cond_destroy(&monitorObj->is_occupied_bird);
  
  free(catThreads);
  free(dogThreads);
  free(birdThreads);
}
