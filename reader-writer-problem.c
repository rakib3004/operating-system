#include<semaphore.h>
#include<stdio.h>
#include<pthread.h>

void *reader(void *);
void *writer(void *);

int readcount=0,writecount=0,sh_var=5,bsize[5];
sem_t a,b,c,rsem,wsem;
pthread_t r[3],w[2];

void *reader(void *i)
{
        printf("\n-------------------------");
        printf("\n\n reader- %d is reading", i );

        sem_wait(&c);
        sem_wait(&rsem);
        sem_wait(&a);
        readcount++;
        if(readcount==1)
            sem_wait(&wsem);
        sem_post(&a);
        sem_post(&rsem);
        sem_post(&c);
        printf("\nupdated value : %d ",sh_var);
        sem_wait(&a);
        readcount--;
        if(readcount==0)
            sem_post(&wsem);
        sem_post(&a);
}

void *writer(void *i)
{
        printf("\n\n writer- %d is writing",i);
        sem_wait(&b);
        writecount++;
        if(writecount==1)
        sem_wait(&rsem);
        sem_post(&b);
        sem_wait(&wsem);

        sh_var=sh_var+5;
        sem_post(&wsem);
        sem_wait(&b);
        writecount--;
        if(writecount==0)
        sem_post(&rsem);
        sem_post(&b);
}

int main()
{
        sem_init(&a,0,1);
        sem_init(&wsem,0,1);
        sem_init(&b,0,1);
        sem_init(&c,0,1);
        sem_init(&rsem,0,1);

        pthread_create(&r[0],NULL,(void *)reader,(void *)0);
        pthread_create(&w[0],NULL,(void *)writer,(void *)0);
        pthread_create(&r[1],NULL,(void *)reader,(void *)1);
        pthread_create(&r[2],NULL,(void *)reader,(void *)2);
        pthread_create(&r[3],NULL,(void *)reader,(void *)3);
        pthread_create(&w[1],NULL,(void *)writer,(void *)3);
        pthread_create(&r[4],NULL,(void *)reader,(void *)4);

        pthread_join(r[0],NULL);
        pthread_join(w[0],NULL);
        pthread_join(r[1],NULL);
        pthread_join(r[2],NULL);
        pthread_join(r[3],NULL);
        pthread_join(w[1],NULL);
        pthread_join(r[4],NULL);

        return(0);
}
