#include<stdio.h>

int array[6]={1,4,3,7,50,2};
int main(){

int n1=fork();
int n2=fork();
int i,j;
int c=0;
if(n1>0&&n2>0){
for(i=0;i<6;i++){
c++;

}
printf("%d\n",c);

}


else if(n1==0&&n2>0){
int sum=0;
for(i=0;i<6;i++){
if(array[i]%2==0){
sum=sum+array[i];
}
}
printf("%d\n",sum);

}
else if(n1>0&&n2==0){
for(i=0;i<6;i++){
if(array[i]%2==1){
printf("%d ",array[i]);
}
}

}
else{
for(i=0;i<6;i++){
for(j=i+1;j<5;j++){
if(array[i]>array[j]){
int temp;

temp = array[j];
array[j]=array[i];
array[i]=temp;
}

}

}
printf("The sorted array is : ");
for(i=0;i<6;i++){

printf("%d ",array[i]);
}
}

}
