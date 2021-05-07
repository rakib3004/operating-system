#include<stdio.h>
#include<pthread.h>
#include<stdatomic.h>
#include<stdlib.h>

#define BUFFER_SIZE 5
int in, out, current_size, input_index;
const int ITR_LIMIT = 200;
int buffer[BUFFER_SIZE];
int produced, consumed, produced_index;
int input[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77,
78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};
atomic_int flag = 0;
atomic_int lock = 0;
atomic_int blank = 1, full = 0;
atomic_int counter=0;

void *producer();
void *consumer();

struct arg_struct {
    int arg1;
};

atomic_int testAndSet(atomic_int *value)
{
    atomic_int ret = *value;
    *value = 1;
    return ret;
}

void myWait(atomic_int *semaphore)
{
    while(*semaphore<=0);
    //while(testAndSet(&flag));
    (*semaphore)--;
    //flag=0;
}

void mySignal(atomic_int *semaphore)
{
    while(testAndSet(&flag)) ;
    (*semaphore)++;
    flag=0;
}

int main()
{
    pthread_t p1, p2,p3, p4;
    struct arg_struct args,args2,args3,args4;
    args.arg1 = 1;
    pthread_create(&p1, NULL, (void*)&producer, (void*)&args);
    args2.arg1 =1;
	pthread_create(&p2, NULL, (void*)&consumer, (void*)&args2);
	args3.arg1=2;
	pthread_create(&p3, NULL, (void*)&producer, (void*)&args3);
	args4.arg1=2;
	pthread_create(&p4, NULL, (void*)&consumer, (void*)&args4);
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	pthread_join(p3, NULL);
	pthread_join(p4, NULL);
}

void *producer(void *arg)
{
    //printf("dhuksi");
    int n = ((struct arg_struct*)arg)->arg1;
    while(counter++<ITR_LIMIT)
    {
        myWait(&blank);
        /*while(testAndSet(&flag)||current_size==BUFFER_SIZE)
        {
            if(current_size==BUFFER_SIZE)
            {
                //printf("in");
                flag=0;
            }
        }*/
        //while(testAndSet(&lock))printf("");
        produced = input[input_index++];
        buffer[in] = produced;
        current_size++;
        printf("Producer %d produced = %d\n" ,n,produced);
        printf("current status of the queue : ");
        if(current_size==0)
            printf("BLANK\n");
        else
        {
            for(int i=0;i<BUFFER_SIZE;i++)
            {
                if(buffer[i]!=NULL)
                    printf("%d ",buffer[i]);
            }
            printf("\n");
        }
        in = (in+1)%BUFFER_SIZE;
        //flag=0;

        mySignal(&full);
        lock = 0;
    }
}

void *consumer(void* arg)
{
    //printf("dhukse");
    int n = ((struct arg_struct*)arg)->arg1;
    while(counter++<ITR_LIMIT)
    {
        myWait(&full);
        /*while(testAndSet(&flag)||current_size==0);*/
        //while(testAndSet(&lock)) printf("");
        consumed = buffer[out];
        buffer[out]=NULL;
        current_size--;
        printf("Consumer %d consumed = %d\n" ,n,consumed);
        printf("current status of the queue : ");
        if(current_size==0)
            printf("BLANK\n");
        else
        {
            for(int i=0;i<BUFFER_SIZE;i++)
            {
                if(buffer[i]!=NULL)
                    printf("%d ",buffer[i]);
            }
            printf("\n");
        }

        out=(out+1)%BUFFER_SIZE;
        //flag=0;

        mySignal(&blank);
        lock = 0;

    }
}
