#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t reader_process,writer_process;
int value = 0,rcount = 0;

void *reader(void *arg)
{
  int f;
  f = ((int)arg);
  sem_wait(&reader_process);
  rcount++;
  
  if(rcount==1){
    sem_wait(&writer_process);
  }

  sem_post(&reader_process);
  printf("Reader: %d reads, value= %d\n",f,data);

  sem_wait(&reader_process);
  rcount--;
  if(rcount==0)
  {
      sem_post(&writer_process);

  }

  sem_post(&reader_process);
  
}

void *writer(void *arg)
{
  int f;
  f = ((int) arg);
  sem_wait(&writer_process);
  value++;
  printf("Writer: %d writes, value= %d\n",f,data);
  
  sem_post(&writer_process);

}

int main()
{
  int i;
  pthread_t reader_t_id[10],writer_t_id[10];
  
  sem_init(&reader_process,0,1);
  sem_init(&writer_process,0,1);
  
  
  for(i=0;i<10;i++)
  {
    pthread_create(&writer_t_id[i],NULL,writer,(void *)i);
    pthread_create(&reader_t_id[i],NULL,reader,(void *)i);
  }
  for(i=0;i<10;i++)
  {
    pthread_join(writer_t_id[i],NULL);
    pthread_join(reader_t_id[i],NULL);
  }
  return 0;
}
