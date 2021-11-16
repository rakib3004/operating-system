#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main(){

pid_t pid;
printf("Mushfiq said Aynabahini");


pid = fork();

printf("The ID is: %d ",pid);

if(pid<0){
fprintf(stderr, "Fork Failed");
return 1;

}

else if(pid ==0){
//execlp("/bin/ls", "ls", NULL);

}

else{

wait(NULL);

printf("Child Complete");


}
return 0;


}
