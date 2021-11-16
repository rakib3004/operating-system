#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main(){

pid_t pid, pid2, pid3, pid4;

printf("Process 1 ID is: %d \n",pid);
pid = fork();
pid2 = fork();
pid3 = fork();
pid4 = fork();


printf("Process 2 ID is: %d \n",pid);

if(pid<0){
fprintf(stderr, "Fork Failed\n");
return 1;

}

else if(pid ==0){
//execlp("/bin/ls", "ls", NULL);
printf("Process 3 ID is: %d \n",pid);


}

else{

wait(NULL);

printf("Process 4 ID is: %d \n",pid);


}
return 0;


}
