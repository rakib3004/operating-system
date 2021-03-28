

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int sum;
int flag =0;
void *worker_thread(void *arg)
{
    int i;
    int n = atoi(arg);

    if(flag)
    {
        n=((n+1)/2);
        i=1;
    }
    else
    {

        i=n/2+1;
    }
    //printf("%d %d\n",flag,n);
     sum=0;

    for(;i<=n;i++)sum+=i;

    pthread_exit(NULL);

}

int main(int argc, char *argv[])
{
        int s=0;
        pthread_t thread,thread1;
        flag =1;
        pthread_create(&thread, NULL, worker_thread, argv[1]);
        pthread_join(thread, NULL);
        //printf("%d\n",sum);
        s+=sum;
        flag=0;
        pthread_create(&thread1, NULL, worker_thread, argv[1]);
        pthread_join(thread1, NULL);
        s+=sum;

       printf("%d\n",s);

}
