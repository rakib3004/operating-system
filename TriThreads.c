#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int sum;

void *runner(void *param);
int flag=0;
int main(int argc, char *argv[] ){

pthread_t tid,tid2;
//
//pthread_attr_t attr;
//
//pthread_attr_init(&attr);
int m=0;

  flag=1;
pthread_create(&tid,NULL,runner,argv[1]);

pthread_join(tid,NULL);
m=m+sum;

flag=0;
pthread_create(&tid2,NULL,runner,argv[1]);

pthread_join(tid2,NULL);
m=m+sum;
printf("sum =%d\n",m);


}


void *runner(void *param){
int i ,upper=atoi(param);
sum=0;

if(flag==0){
for(i=0;i<=upper;i++){
if(i%2==1){

sum+=i;
}

}


}
else{


for(i=0;i<=upper;i++){
if(i%2==0){

sum+=i;
}

}

}

pthread_exit(0);

}

