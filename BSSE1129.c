#include<semaphore.h>
#include<stdio.h>
#include<pthread.h>

void *reader(void *);
void *writer(void *);

sem_t a,b,read_semaphore,write_semaphore;
pthread_t read[5],write[5];

int readcount=0,writecount=0,sh_var=5,bsize[5];


void *reader(void *i)
{
        printf("\n-------------------------");
        printf("\n\n reader- %d is reading", i );

        sem_wait(&read_semaphore);
        sem_wait(&a);
        readcount++;
        if(readcount==1)
            sem_wait(&write_semaphore);
        sem_post(&a);
        sem_post(&read_semaphore);
        printf("\nupdated value : %d ",sh_var);
        sem_wait(&a);
        readcount--;
        if(readcount==0)
            sem_post(&write_semaphore);
        sem_post(&a);
}

void *writer(void *i)
{
        printf("\n\n writer- %d is writing",i);
        sem_wait(&b);
        writecount++;
        if(writecount==1)
        sem_wait(&read_semaphore);
        sem_post(&b);
        sem_wait(&write_semaphore);

        sh_var=sh_var+5;
        sem_post(&write_semaphore);
        sem_wait(&b);
        writecount--;
        if(writecount==0)
        sem_post(&read_semaphore);
        sem_post(&b);
}

int main()
{
        sem_init(&a,0,1);
        sem_init(&write_semaphore,0,1);
        sem_init(&b,0,1);
        sem_init(&read_semaphore,0,1);



        pthread_create(&read[0],NULL,(void *)reader,(void *)0);
        pthread_create(&write[0],NULL,(void *)writer,(void *)0);

        pthread_create(&read[1],NULL,(void *)reader,(void *)1);
        pthread_create(&read[2],NULL,(void *)reader,(void *)2);
        pthread_create(&write[1],NULL,(void *)writer,(void *)2);



        pthread_join(read[0],NULL);
        pthread_join(write[0],NULL);


        pthread_join(read[1],NULL);
        pthread_join(read[2],NULL);
        pthread_join(write[1],NULL);

        return(0);
}

