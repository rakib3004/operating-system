
#include<bits/stdc++.h>
using namespace std;
int main(){



int BUFFER_SIZE=5;
int counter=0;
int *turn=0;
int x=0;
int i=0,j=1;
bool flag[2];
int buffer[5]={0};
int in=0;
int out=0;
int nextProduced=0;
int nextConsumed=0;
while(true){



flag[j]=true;
*turn=i;
while(flag[i]==true&&*turn==i);
//critical section start
    while(counter==BUFFER_SIZE){
        nextProduced = x++;
        buffer[in]=nextProduced;
        in = (in+1)%BUFFER_SIZE;
        counter++;
    }
// critical section end





flag[i]=true;
*turn=j;
while(flag[j]==true&&*turn==j);
//critical section start
    while(counter==0){
        nextProduced = buffer[out];
        out = (out+1)%BUFFER_SIZE;
        counter--;
    }
// critical section end
}

return 0;
}
