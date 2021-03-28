#include<stdio.h>
int main()
{
int x=1;

pid_t  pid = fork();

if(pid==0){
printf("Child has x= %d\n",++x);
}
else
printf("Parent has x= %d\n",--x);


return 0;
}

